// RUN: %dxc -E main  -T cs_6_0 %s


RWBuffer< int > g_Intensities : register(u1);

groupshared int sharedData;

int a;
int b[2];
[ numthreads( 64, 2, 2 ) ]
void main( uint GI : SV_GroupIndex, uint GID : SV_GroupID)
{
sharedData = b[GID] + a;
InterlockedAdd(sharedData, g_Intensities[GI]);
g_Intensities[GI] = sharedData;
}