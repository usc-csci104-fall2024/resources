#include <vector>
#include <string>
#include <unordered_map>
#include <fstream>
#include <user_code_runner.h>
#include <gtest/gtest.h>

struct Rectangle {
    int length;
    int height;
};

void evaluateFloorplan()
{
    // Run student's floorplan executable
    std::string testSuiteName = testing::UnitTest::GetInstance()->current_test_info()->test_suite_name();
    std::string testCaseName = testing::UnitTest::GetInstance()->current_test_info()->name();
    std::string inputFile = TEST_BINARY_DIR "/floorplan_tests/inputs/" +  testCaseName + ".in";
    std::string outputFile = TEST_BINARY_DIR "/floorplan_tests/student_outputs/" + testCaseName + ".out";
    {
        std::string workingDirectory = TEST_BINARY_DIR;
        std::string executablePath = FLOORPLAN_EXECUTABLE;
        std::vector<std::string> args {inputFile, outputFile};
        bool useValgrind = testSuiteName.find("Stress") == std::string::npos;

        UserCodeRunner runner {workingDirectory, executablePath, args, outputFile, useValgrind};
        runner.setCheckExitCode(false);
        ASSERT_TRUE(runner.execute());
    }

    // Parse input file for ourselves
    int boardLength, boardHeight, numRectangles;
    std::unordered_map<int, Rectangle> rectangles;
    {
        std::ifstream inputFileStream {inputFile};
        ASSERT_TRUE(inputFileStream) << "Couldn't open input file (" << inputFile << ")";
        inputFileStream >> boardLength >> boardHeight >> numRectangles;
        for(int i = 0; i < numRectangles; ++i) {
            int id;
            inputFileStream >> id;
            inputFileStream >> rectangles[id].length >> rectangles[id].height;
        }
    }

    std::ifstream outputFileStream {outputFile};
    ASSERT_TRUE(outputFileStream) << "Couldn't open output file (" << outputFile << ")";

    // Evaluate student output
    if(testSuiteName.find("NoSolution") != std::string::npos) {
        std::string line;
        std::getline(outputFileStream, line);
        ASSERT_NE(line.find("No solution found."), std::string::npos);
        return;
    }

    std::unordered_map<int, bool> rectanglesSeen;
    std::vector<std::vector<std::pair<bool, int>>> board(boardLength, std::vector<std::pair<bool, int>>(boardHeight, std::make_pair(false, 0)));
    int outputRectangleCount = 0;
    int id, x, y, length, height;
    while(outputFileStream >> id >> x >> y >> length >> height) {
        // Ensure ID is valid
        rectanglesSeen[id] = true;
        ASSERT_NE(rectangles.find(id), rectangles.end()) << "ID " << id << " in the output does not correspond to any rectangle in the input.";

        // Test that length and height match the input rectangle
        ASSERT_EQ(std::minmax(rectangles[id].length, rectangles[id].height), std::minmax(length, height)) << "ID " << id << " has incorrect rectangle dimensions.";

        // Test that rectangle is fully in bounds
        ASSERT_GE(x, 0);
        ASSERT_GE(y, 0);
        ASSERT_LE(x+length, boardLength);
        ASSERT_LE(y+height, boardHeight);

        // Try placing rectangle
        for(int i = x; i < x+length; ++i) {
            for(int j = y; j < y+height; ++j) {
                ASSERT_FALSE(board[i][j].first) << "Rectangle " << id << " overlaps " << board[i][j].second << " at (" << i << ", " << j << ")";
                board[i][j].first = true;
                board[i][j].second = id;
            }
        }

        ++outputRectangleCount;
    }

    ASSERT_EQ(outputRectangleCount, numRectangles);
    ASSERT_EQ(rectanglesSeen.size(), numRectangles) << "Each rectangle should be assigned seperately and uniquely in the output.";
}


/*
When each test case runs evaluateFloorplan, it determines what input file to use based on the
test case name.

If the test suite is "Floorplan", we check that the student's proposed solution is valid and
actually works.

If the test suite is "FloorplanNoSolution", we check that the student returned "No solution found."
*/


TEST(Floorplan, Example1)
{
    evaluateFloorplan();
}

TEST(Floorplan, Example3)
{
	evaluateFloorplan();
}

TEST(Floorplan, OneByOne)
{
	evaluateFloorplan();
}

TEST(Floorplan, TwoByOne_SinglePiece_NoRotation)
{
	evaluateFloorplan();
}

TEST(Floorplan, OneByTwo_SinglePiece_NoRotation)
{
	evaluateFloorplan();
}

TEST(Floorplan, TwoByOne_SinglePiece_Rotation)
{
	evaluateFloorplan();
}

TEST(Floorplan, OneByTwo_SinglePiece_Rotation)
{
	evaluateFloorplan();
}

TEST(Floorplan, ThreeByTwo_ThreePieces_NoRotation)
{
	evaluateFloorplan();
}

TEST(Floorplan, ThreeByTwo_TwoPieces_Rotation)
{
	evaluateFloorplan();
}

TEST(Floorplan, TwoByTwo_TwoPieces_ExtraSpace)
{
	evaluateFloorplan();
}

TEST(Floorplan, TenByTen)
{
	evaluateFloorplan();
}

TEST(Floorplan, 20by20_Random)
{
	evaluateFloorplan();
}

TEST(Floorplan, 50by100_Random)
{
	evaluateFloorplan();
}

TEST(FloorplanStress, 500by2000_Random)
{
	evaluateFloorplan();
}


TEST(FloorplanNoSolution, Example2)
{
	evaluateFloorplan();
}

TEST(FloorplanNoSolution, TwoByOne_NoSolution)
{
	evaluateFloorplan();
}

TEST(FloorplanNoSolutionStress, TenByTen_Oversized)
{
	evaluateFloorplan();
}

TEST(FloorplanNoSolution, 50by100_Random_NoSolution)
{
	evaluateFloorplan();
}

TEST(FloorplanNoSolution, TwoByTwo_ImpossibleStack)
{
	evaluateFloorplan();
}
