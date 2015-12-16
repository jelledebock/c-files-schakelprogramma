#include <gtest/gtest.h>
#include "../figuren.h"
#include <fstream>

TEST(FigurenTest, leesintest)
{
    Cirkel cirkel(2.0);

    ifstream infile;
    infile.open("testfile.txt");
    Figuur * cp = lees_figuur(infile);
    infile.close();

    EXPECT_EQ(cirkel.oppervlakte(),cp->oppervlakte());
    EXPECT_EQ(cirkel.omtrek(),cp->omtrek());
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}
