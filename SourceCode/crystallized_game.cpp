#include "all.h"
#include <stdio.h>

int crystallized_game_state;

bool in_game = true;

int score = 0;

Note notes_cry[] = {
      { 542, 0, VECTOR2(0,0), VECTOR2()},
      { 583, 1, VECTOR2(1,0), VECTOR2(1,0)},
           
      { 625, 0, VECTOR2(1,0), VECTOR2()},
      { 645, 1, VECTOR2(2,0), VECTOR2(1,0)},
      { 666, 1, VECTOR2(1,0), VECTOR2(-1,0)},
      { 687, 1, VECTOR2(2,0), VECTOR2(1,0)},
           
      { 708, 0, VECTOR2(2,0), VECTOR2()},
      { 749, 1, VECTOR2(3,0), VECTOR2(1,0)},
           
      { 790, 0, VECTOR2(3,0), VECTOR2()},
      { 832, 1, VECTOR2(3,1), VECTOR2(0,1)},
           
      { 873, 0, VECTOR2(3,1), VECTOR2()},
      { 914, 1, VECTOR2(2,1), VECTOR2(-1,0)},
           
      { 956, 0, VECTOR2(2,1), VECTOR2()},
      { 976, 1, VECTOR2(1,1), VECTOR2(-1,0)},
      { 997, 1, VECTOR2(2,1), VECTOR2(1,0)},
      { 1018, 1, VECTOR2(1,1), VECTOR2(-1,0)},
  
      { 1039, 0, VECTOR2(1,1), VECTOR2()},
      { 1080, 1, VECTOR2(0,1), VECTOR2(-1,0)},
  
      { 1121, 0, VECTOR2(0,1), VECTOR2()},
  
      { 1162, 1, VECTOR2(0,0), VECTOR2(0,-1)},
      { 1183, 1, VECTOR2(0,1), VECTOR2(0,1)},
      { 1202, 1, VECTOR2(0,2), VECTOR2(0,1)},
      { 1204, 0, VECTOR2(0,2), VECTOR2()},
      { 1245, 1, VECTOR2(1,2), VECTOR2(1,0)},
  
      { 1287, 0, VECTOR2(1,2), VECTOR2()},
      { 1328, 1, VECTOR2(2,2), VECTOR2(1,0)},
  
      { 1370, 0, VECTOR2(2,2), VECTOR2()},
      { 1411, 1, VECTOR2(3,2), VECTOR2(1,0)},
     
      { 1452, 0, VECTOR2(3,2), VECTOR2()},
      { 1473, 1, VECTOR2(3,3), VECTOR2(0,1)},
      { 1494, 1, VECTOR2(3,2), VECTOR2(0,-1)},
      { 1514, 1, VECTOR2(3,3), VECTOR2(0,1)},
  
      { 1535, 0, VECTOR2(3,3), VECTOR2()},
      { 1576, 1, VECTOR2(2,3), VECTOR2(-1,0)},
  
      { 1618, 0, VECTOR2(2,3), VECTOR2()},
      { 1659, 1, VECTOR2(1,3), VECTOR2(-1,0)},
  
      { 1701, 0, VECTOR2(1,3), VECTOR2()},
      { 1742, 1, VECTOR2(0,3), VECTOR2(-1,0)},
  
      { 1783, 0, VECTOR2(0,3), VECTOR2()},
  
      { 1825-3, 2, VECTOR2(0,2), VECTOR2(0,0), VECTOR2(0,-1)},
      { 1825-3, 2, VECTOR2(0,1), VECTOR2(0,0), VECTOR2(0,-1)},
      { 1825-3, 2, VECTOR2(0,0), VECTOR2(0,0), VECTOR2(0,-1)},
  
      { 1866, 0, VECTOR2(0,0), VECTOR2()},
  
      { 1949, 0, VECTOR2(0,1), VECTOR2()},
  
  { 2011, 0, VECTOR2(1,1), VECTOR2()},
  { 2032, 0, VECTOR2(1,2), VECTOR2()},
  
  { 2073, 0, VECTOR2(1,2), VECTOR2()},
  
  { 2114, 0, VECTOR2(2,2), VECTOR2()},
  
  { 2156, 0, VECTOR2(2,2), VECTOR2()},
  { 2176, 0, VECTOR2(3,2), VECTOR2()},
  { 2197, 0, VECTOR2(2,2), VECTOR2()},
  
  { 2239, 0, VECTOR2(2,3), VECTOR2()},
  
  { 2280, 0, VECTOR2(3,3), VECTOR2()},
  
  { 2342, 0, VECTOR2(2,2), VECTOR2()},
  
  { 2365, 0, VECTOR2(2,1), VECTOR2()},
  { 2383, 0, VECTOR2(3,1), VECTOR2()},
  
  { 2425, 0, VECTOR2(3,0), VECTOR2()},
  { 2445, 0, VECTOR2(3,0), VECTOR2()},
  
  { 2487, 0, VECTOR2(2,0), VECTOR2()},
  
  { 2528, 0, VECTOR2(1,0), VECTOR2()},
  
  { 2590, 0, VECTOR2(1,1), VECTOR2()},
  
  { 2632, 0, VECTOR2(1,2), VECTOR2()},
  
  { 2673, 0, VECTOR2(2,3), VECTOR2()},
  { 2694, 0, VECTOR2(3,3), VECTOR2()},
  
  { 2809, 0, VECTOR2(2,2), VECTOR2()},
  { 2839, 0, VECTOR2(1,1), VECTOR2()},
  { 2859, 0, VECTOR2(0,0), VECTOR2()},
  
  { 3004, 0, VECTOR2(1,0), VECTOR2()},
  { 3025, 0, VECTOR2(2,0), VECTOR2()},
  { 3045, 0, VECTOR2(2,1), VECTOR2()},
  
  { 3087, 0, VECTOR2(2,2), VECTOR2()},
  { 3108, 0, VECTOR2(3,3), VECTOR2()},
  
      { 3189, 0, VECTOR2(3, 2), VECTOR2() },
      { 3231, 0, VECTOR2(2, 2), VECTOR2() },
      { 3272, 0, VECTOR2(1, 2), VECTOR2() },
      { 3303, 0, VECTOR2(1, 3), VECTOR2() },
      { 3334, 0, VECTOR2(0, 2), VECTOR2() },
      { 3376, 0, VECTOR2(0, 3), VECTOR2() },
      { 3386, 1, VECTOR2(0, 2), VECTOR2(0,-1) },
      { 3397, 0, VECTOR2(0, 2), VECTOR2() },
      { 3408, 1, VECTOR2(0, 1), VECTOR2(0,-1) },
      { 3420, 0, VECTOR2(0, 1), VECTOR2() },
  
      { 3437, 0, VECTOR2(1, 0), VECTOR2() },
      { 3471, 0, VECTOR2(2, 0), VECTOR2() },
      { 3501, 0, VECTOR2(2, 1), VECTOR2() },
  
      { 3544, 0, VECTOR2(3, 0), VECTOR2() },
      { 3554, 1, VECTOR2(3, 1), VECTOR2(0,1) },
      { 3566, 0, VECTOR2(3, 1), VECTOR2() },
      { 3577, 1, VECTOR2(3, 2), VECTOR2(0,1) },
      { 3587, 0, VECTOR2(3, 2), VECTOR2() },
  
      { 3607, 0, VECTOR2(3, 3), VECTOR2() },

    { 3637, 0, VECTOR2(2, 2), VECTOR2() },
    { 3669, 0, VECTOR2(1, 1), VECTOR2() },
    { 3707, 0, VECTOR2(1, 0), VECTOR2() },
    { 3739, 0, VECTOR2(2, 0), VECTOR2() },
    { 3751, 0, VECTOR2(1, 1), VECTOR2() },
    { 3770, 0, VECTOR2(2, 1), VECTOR2() },
    { 3813, 0, VECTOR2(2, 2), VECTOR2() },
    { 3852, 0, VECTOR2(3, 2), VECTOR2() },
    { 3893, 0, VECTOR2(3, 2), VECTOR2() },

    { 3914, 1, VECTOR2(2, 2), VECTOR2(-1,0) },
    { 3926, 1, VECTOR2(1, 2), VECTOR2(-1,0) },
    { 3937, 1, VECTOR2(0, 2), VECTOR2(-1,0) },

    { 3966, 2, VECTOR2(1, 2), VECTOR2(3,2), VECTOR2(1,0) },
    { 3966, 2, VECTOR2(2, 2), VECTOR2(3,2), VECTOR2(1,0) },
    { 3966, 2, VECTOR2(3, 2), VECTOR2(3,2), VECTOR2(1,0) },
    { 4003 , 0, VECTOR2(3, 2), VECTOR2() },
    { 4034, 0, VECTOR2(3, 2), VECTOR2() },
    { 4056, 0, VECTOR2(3, 2), VECTOR2() },
    { 4074, 1, VECTOR2(3, 1), VECTOR2(0,-1) },
    { 4086, 1, VECTOR2(2, 1), VECTOR2(-1,0) },
    { 4097, 1, VECTOR2(1, 1), VECTOR2(-1,0) },
    { 4128, 1, VECTOR2(0, 1), VECTOR2(-1,0) },
    { 4160, 0, VECTOR2(0, 0), VECTOR2() },
    { 4200, 0, VECTOR2(1, 0), VECTOR2() },
    { 4220, 0, VECTOR2(2, 0), VECTOR2() },
    { 4241, 1, VECTOR2(2, 1), VECTOR2(0,1) },
    { 4253, 1, VECTOR2(2, 2), VECTOR2(0,1) },
    { 4263, 1, VECTOR2(2, 3), VECTOR2(0,1) },
    { 4296, 0, VECTOR2(2, 3), VECTOR2() },
    { 4324, 0, VECTOR2(1, 2), VECTOR2() },
    { 4361, 0, VECTOR2(0, 2), VECTOR2() },
    { 4371, 0, VECTOR2(1, 2), VECTOR2() },
    { 4401, 0, VECTOR2(2, 2), VECTOR2() },
    { 4410, 0, VECTOR2(1, 2), VECTOR2() },
    { 4442, 0, VECTOR2(1, 3), VECTOR2() },
    { 4452, 0, VECTOR2(1, 2), VECTOR2() },
    { 4481, 0, VECTOR2(1, 1), VECTOR2() },
    { 4491, 0, VECTOR2(1, 2), VECTOR2() },

    { 4509, 0, VECTOR2(2, 2), VECTOR2() },

    { 4531, 0, VECTOR2(2, 2), VECTOR2() },
    { 4541, 1, VECTOR2(2, 3), VECTOR2(0,1) },

    { 4561, 0, VECTOR2(2, 3), VECTOR2() },
    { 4572, 1, VECTOR2(3, 3), VECTOR2(1,0) },

    { 4594, 0, VECTOR2(3, 2), VECTOR2() },

    { 4614, 0, VECTOR2(3, 2), VECTOR2() },
    { 4625, 1, VECTOR2(3, 1), VECTOR2(0,-1) },

    { 4645, 0, VECTOR2(3, 1), VECTOR2() },
    { 4656, 1, VECTOR2(2, 1), VECTOR2(-1,0) },

    { 4678, 0, VECTOR2(1, 1), VECTOR2() },

    { 4698, 0, VECTOR2(1, 1), VECTOR2() },
    { 4709, 1, VECTOR2(0, 1), VECTOR2(-1,0) },

    { 4728, 0, VECTOR2(0, 1), VECTOR2() },
    { 4740, 1, VECTOR2(0, 2), VECTOR2(0,1) },

    { 4760, 0, VECTOR2(1, 2), VECTOR2() },

    { 4779, 0, VECTOR2(1, 2), VECTOR2() },
    { 4790, 1, VECTOR2(1, 1), VECTOR2(0,-1) },

    { 4810, 0, VECTOR2(1, 1), VECTOR2() },
    { 4821, 1, VECTOR2(0, 1), VECTOR2(-1,0) },

    { 4843, 0, VECTOR2(0, 0), VECTOR2() },
    { 4863, 2, VECTOR2(0, 1), VECTOR2(0,3), VECTOR2(0,1) },
    { 4863, 2, VECTOR2(0, 2), VECTOR2(0,3), VECTOR2(0,1) },
    { 4863, 2, VECTOR2(0, 3), VECTOR2(0,3), VECTOR2(0,1) },
    { 4884, 0, VECTOR2(0, 3), VECTOR2() },
    { 4904, 2, VECTOR2(1, 3), VECTOR2(3,3), VECTOR2(1,0) },
    { 4904, 2, VECTOR2(2, 3), VECTOR2(3,3), VECTOR2(1,0) },
    { 4904, 2, VECTOR2(3, 3), VECTOR2(3,3), VECTOR2(1,0) },
    { 4925, 0, VECTOR2(3, 3), VECTOR2() },
    { 4946, 2, VECTOR2(3, 2), VECTOR2(3,0), VECTOR2(0,-1) },
    { 4946, 2, VECTOR2(3, 1), VECTOR2(3,0), VECTOR2(0,-1) },
    { 4946, 2, VECTOR2(3, 0), VECTOR2(3,0), VECTOR2(0,-1) },
    { 4966, 0, VECTOR2(3, 0), VECTOR2() },
    { 4986, 2, VECTOR2(2, 0), VECTOR2(0,0), VECTOR2(-1,0) },
    { 4986, 2, VECTOR2(1, 0), VECTOR2(0,0), VECTOR2(-1,0) },
    { 4986, 2, VECTOR2(0, 0), VECTOR2(0,0), VECTOR2(-1,0) },

  { 5006, 0, VECTOR2(0, 0), VECTOR2() },
  { 5016, 0, VECTOR2(0, 1), VECTOR2() },
  { 5027, 0, VECTOR2(1, 1), VECTOR2() },
  { 5038, 0, VECTOR2(2, 1), VECTOR2() },
  { 5049, 0, VECTOR2(2, 2), VECTOR2() },
  { 5060, 0, VECTOR2(2, 3), VECTOR2() },
  { 5071, 0, VECTOR2(3, 3), VECTOR2() },
  { 5081, 0, VECTOR2(3, 2), VECTOR2() },
  { 5091, 0, VECTOR2(2, 2), VECTOR2() },

  { 5110, 0, VECTOR2(1, 2), VECTOR2() },
  { 5140, 0, VECTOR2(1, 2), VECTOR2() },
  { 5150, 0, VECTOR2(1, 2), VECTOR2() },

  { 5172, 0, VECTOR2(1, 2), VECTOR2() },

  { 5193, 0, VECTOR2(2, 3), VECTOR2() },
  { 5203, 0, VECTOR2(3, 3), VECTOR2() },

  { 5224, 0, VECTOR2(2, 2), VECTOR2() },
  { 5234, 0, VECTOR2(3, 2), VECTOR2() },

  { 5254, 0, VECTOR2(2, 2), VECTOR2() },
  { 5265, 0, VECTOR2(1, 2), VECTOR2() },

  { 5285, 0, VECTOR2(1, 1), VECTOR2() },
  { 5295, 0, VECTOR2(1, 0), VECTOR2() },

  { 5318, 0, VECTOR2(0, 0), VECTOR2() },
  { 5329, 0, VECTOR2(1, 1), VECTOR2() },
  { 5338, 0, VECTOR2(2, 2), VECTOR2() },

  { 5357, 0, VECTOR2(2, 1), VECTOR2() },
  { 5367, 1, VECTOR2(1, 1), VECTOR2(-1,0) },
  { 5378, 0, VECTOR2(1, 1), VECTOR2() },

  { 5398, 0, VECTOR2(1, 2), VECTOR2() },
  { 5409, 0, VECTOR2(2, 2), VECTOR2() },

  { 5429, 0, VECTOR2(3, 2), VECTOR2() },
  { 5440, 0, VECTOR2(3, 3), VECTOR2() },
  { 5451, 0, VECTOR2(2, 3), VECTOR2() },
  { 5461, 0, VECTOR2(2, 2), VECTOR2() },
  { 5471, 0, VECTOR2(1, 2), VECTOR2() },
  { 5482, 0, VECTOR2(1, 1), VECTOR2() },

  { 5502, 0, VECTOR2(1, 2), VECTOR2() },

  { 5523, 0, VECTOR2(1, 2), VECTOR2() },
  { 5533, 1, VECTOR2(1, 1), VECTOR2(0,-1) },

  { 5554, 0, VECTOR2(1, 0), VECTOR2() },
  { 5565, 1, VECTOR2(0, 0), VECTOR2(-1,0) },

  { 5583, 0, VECTOR2(0, 1), VECTOR2() },
  { 5594, 1, VECTOR2(1, 1), VECTOR2(1,0) },

  { 5614, 0, VECTOR2(1, 2), VECTOR2() },
  { 5626, 1, VECTOR2(2, 2), VECTOR2(1,0) },

  { 5649, 0, VECTOR2(2, 3), VECTOR2() },
  { 5659, 1, VECTOR2(3, 3), VECTOR2(1,0) },
  { 5668, 0, VECTOR2(3, 3), VECTOR2() },

  { 5688, 0, VECTOR2(3, 2), VECTOR2() },
  { 5709, 0, VECTOR2(2, 2), VECTOR2() },





    { 5831, 0, VECTOR2(2, 2), VECTOR2() },

    { 5853, 0, VECTOR2(2, 2), VECTOR2() },
    { 5864, 1, VECTOR2(1, 2), VECTOR2(-1,0) },

    { 5883, 0, VECTOR2(1, 2), VECTOR2() },
    { 5894, 1, VECTOR2(1, 3), VECTOR2(0,1) },

    { 5915, 0, VECTOR2(1, 3), VECTOR2() },
    { 5926, 1, VECTOR2(2, 3), VECTOR2(1,0) },

    { 5947, 0, VECTOR2(2, 3), VECTOR2() },
    { 5957, 0, VECTOR2(3, 3), VECTOR2(1,0) },

    { 5977, 0, VECTOR2(2, 2), VECTOR2() },
    { 5988, 0, VECTOR2(1, 1), VECTOR2() },
    { 5999, 0, VECTOR2(2, 2), VECTOR2() },

    { 6019, 0, VECTOR2(2, 2), VECTOR2() },
    { 6030, 1, VECTOR2(1, 2), VECTOR2(-1,0) },
    { 6040, 0, VECTOR2(1, 2), VECTOR2() },
    { 6051, 1, VECTOR2(2, 2), VECTOR2(1,0) },
    { 6061, 0, VECTOR2(2, 2), VECTOR2() },
    { 6072, 0, VECTOR2(1, 2), VECTOR2(-1,0) },

    { 6091, 0, VECTOR2(1, 2), VECTOR2() },
    { 6102, 0, VECTOR2(2, 2), VECTOR2() },

    { 6120, 0, VECTOR2(1, 2), VECTOR2() },

    { 6142, 0, VECTOR2(1, 1), VECTOR2() },

    { 6162, 0, VECTOR2(1, 2), VECTOR2() },

    { 6182, 0, VECTOR2(1, 1), VECTOR2() },

    { 6203, 0, VECTOR2(1, 2), VECTOR2() },

    { 6224, 0, VECTOR2(2, 2), VECTOR2() },
    { 6235, 0, VECTOR2(3, 2), VECTOR2() },

    { 6255, 0, VECTOR2(2, 3), VECTOR2() },
    { 6266, 0, VECTOR2(1, 3), VECTOR2() },

    { 6286, 0, VECTOR2(2, 2), VECTOR2() },

    { 6307, 0, VECTOR2(1, 2), VECTOR2() },
    { 6318, 1, VECTOR2(2, 2), VECTOR2(1,0) },
    { 6328, 0, VECTOR2(2, 2), VECTOR2() },

    { 6348, 0, VECTOR2(2, 2), VECTOR2() },

    { 6369, 0, VECTOR2(1, 3), VECTOR2() },
    { 6380, 0, VECTOR2(2, 3), VECTOR2() },
    { 6390, 0, VECTOR2(3, 3), VECTOR2() },

    { 6410, 0, VECTOR2(2, 2), VECTOR2() },

    { 6431, 0, VECTOR2(1, 1), VECTOR2() },

    { 6451, 0, VECTOR2(0, 0), VECTOR2() },




    { 6494, 0, VECTOR2(0, 0), VECTOR2() },

    { 6534, 0, VECTOR2(0, 0), VECTOR2() },

    { 6555, 2, VECTOR2(1, 0), VECTOR2(3,0), VECTOR2(1,0) },
    { 6555, 2, VECTOR2(2, 0), VECTOR2(3,0), VECTOR2(1,0) },
    { 6555, 2, VECTOR2(3, 0), VECTOR2(3,0), VECTOR2(1,0) },
    { 6565, 0, VECTOR2(3, 0), VECTOR2() },

    { 6586, 2, VECTOR2(2, 0), VECTOR2(0,0), VECTOR2(-1,0) },
    { 6586, 2, VECTOR2(1, 0), VECTOR2(0,0), VECTOR2(-1,0) },
    { 6586, 2, VECTOR2(0, 0), VECTOR2(0,0), VECTOR2(-1,0) },
    { 6597, 0, VECTOR2(0, 0), VECTOR2() },

    { 6617, 0, VECTOR2(1, 1), VECTOR2() },

    { 6638, 0, VECTOR2(0, 0), VECTOR2() },

    { 6659, 0, VECTOR2(1, 1), VECTOR2() },

    { 6680, 0, VECTOR2(2, 2), VECTOR2() },

    { 6700, 0, VECTOR2(3, 3), VECTOR2() },

    { 6742, 2, VECTOR2(3, 2), VECTOR2(3,0), VECTOR2(0,-1) },
    { 6742, 2, VECTOR2(3, 1), VECTOR2(3,0), VECTOR2(0,-1) },
    { 6742, 2, VECTOR2(3, 0), VECTOR2(3,0), VECTOR2(0,-1) },

    { 6762, 2, VECTOR2(3, 1), VECTOR2(3,3), VECTOR2(0,1) },
    { 6762, 2, VECTOR2(3, 2), VECTOR2(3,3), VECTOR2(0,1) },
    { 6762, 2, VECTOR2(3, 3), VECTOR2(3,3), VECTOR2(0,1) },

    { 6783, 1, VECTOR2(3, 2), VECTOR2(0,-1) },
    { 6792, 1, VECTOR2(3, 1), VECTOR2(0,-1) },
    { 6803, 1, VECTOR2(3, 0), VECTOR2(0,-1) },


    { 6824, 0, VECTOR2(2, 0), VECTOR2() },

    { 6865, 0, VECTOR2(3, 0), VECTOR2() },

    { 6886, 2, VECTOR2(2, 0), VECTOR2(0, 0), VECTOR2(-1, 0) },
    { 6886, 2, VECTOR2(1, 0), VECTOR2(0, 0), VECTOR2(-1, 0) },
    { 6886, 2, VECTOR2(0, 0), VECTOR2(0, 0), VECTOR2(-1, 0) },
    { 6897, 0, VECTOR2(0, 0), VECTOR2() },

    { 6917, 2, VECTOR2(1, 0), VECTOR2(3,0), VECTOR2(1,0) },
    { 6917, 2, VECTOR2(2, 0), VECTOR2(3,0), VECTOR2(1,0) },
    { 6917, 2, VECTOR2(3, 0), VECTOR2(3,0), VECTOR2(1,0) },
    { 6928, 0, VECTOR2(2, 0), VECTOR2() },

    { 6947, 0, VECTOR2(2, 1), VECTOR2() },

    { 6968, 0, VECTOR2(1, 2), VECTOR2() },

    { 6988, 0, VECTOR2(2, 2), VECTOR2() },

    { 7009, 0, VECTOR2(2, 3), VECTOR2() },

    { 7030, 0, VECTOR2(2, 3), VECTOR2() },
    { 7041, 1, VECTOR2(2, 2), VECTOR2(0,-1) },
    { 7051, 0, VECTOR2(2, 2), VECTOR2() },
    { 7062, 1, VECTOR2(2, 1), VECTOR2(0,-1) },
    { 7072, 0, VECTOR2(2, 1), VECTOR2() },

    { 7092, 0, VECTOR2(1, 2), VECTOR2() },
    { 7103, 1, VECTOR2(2, 2), VECTOR2(1,0) },

    { 7123, 0, VECTOR2(2, 2), VECTOR2() },
    { 7134, 1, VECTOR2(1, 2), VECTOR2(-1,0) },

    { 7154, 0, VECTOR2(2, 2), VECTOR2() },


    { 7193, 0, VECTOR2(3, 2), VECTOR2() },

    { 7216, 0, VECTOR2(2, 2), VECTOR2() },
    { 7227, 0, VECTOR2(1, 2), VECTOR2() },

    { 7247, 0, VECTOR2(1, 2), VECTOR2() },
    { 7257, 0, VECTOR2(0, 2), VECTOR2() },

    { 7277, 0, VECTOR2(0, 3), VECTOR2() },
    { 7287, 1, VECTOR2(0, 2), VECTOR2(0,-1) },
    { 7298, 0, VECTOR2(0, 2), VECTOR2() },
    { 7309, 1, VECTOR2(0, 1), VECTOR2(0,-1) },
    { 7321, 0, VECTOR2(0, 1), VECTOR2() },


    { 7340, 0, VECTOR2(1, 0), VECTOR2()},

    { 7361, 0, VECTOR2(1, 0), VECTOR2() },
    { 7371, 1, VECTOR2(1, 1), VECTOR2(0,1) },
    { 7382, 0, VECTOR2(1, 1), VECTOR2() },
    { 7393, 1, VECTOR2(1, 2), VECTOR2(0,1) },
    { 7402, 0, VECTOR2(1, 2), VECTOR2() },

    { 7423, 0, VECTOR2(1, 1), VECTOR2() },

    { 7443, 0, VECTOR2(1, 0), VECTOR2() },

    { 7484, 0, VECTOR2(2, 0), VECTOR2() },


    { 7526, 0, VECTOR2(3, 0), VECTOR2() },


    { 7547, 2, VECTOR2(2, 0), VECTOR2(0, 0), VECTOR2(-1, 0)  },
    { 7547, 2, VECTOR2(1, 0), VECTOR2(0, 0), VECTOR2(-1, 0)  },
    { 7547, 2, VECTOR2(0, 0), VECTOR2(0, 0), VECTOR2(-1, 0)  },
    { 7558, 0, VECTOR2(0, 0), VECTOR2() },

    { 7577, 2, VECTOR2(1, 0), VECTOR2(3,0), VECTOR2(1,0) },
    { 7577, 2, VECTOR2(2, 0), VECTOR2(3,0), VECTOR2(1,0) },
    { 7577, 2, VECTOR2(3, 0), VECTOR2(3,0), VECTOR2(1,0) },
    { 7588, 0, VECTOR2(3, 0), VECTOR2() },


    { 7609, 0, VECTOR2(2, 0), VECTOR2() },

    { 7630, 0, VECTOR2(1, 0), VECTOR2() },

    { 7650, 0, VECTOR2(0, 0), VECTOR2() },
    { 7661, 0, VECTOR2(0, 1), VECTOR2() },
    { 7672, 0, VECTOR2(0, 2), VECTOR2() },
    { 7682, 0, VECTOR2(0, 3), VECTOR2() },
    { 7693, 0, VECTOR2(1, 3), VECTOR2() },
    { 7703, 0, VECTOR2(1, 2), VECTOR2() },
    { 7713, 0, VECTOR2(1, 1), VECTOR2() },
    { 7723, 0, VECTOR2(1, 0), VECTOR2() },
    { 7733, 0, VECTOR2(2, 0), VECTOR2() },
    { 7743, 0, VECTOR2(2, 1), VECTOR2() },
    { 7753, 0, VECTOR2(2, 2), VECTOR2() },
    { 7763, 0, VECTOR2(2, 3), VECTOR2() },
    { 7773, 0, VECTOR2(3, 3), VECTOR2() },
    { 7783, 0, VECTOR2(3, 2), VECTOR2() },
    { 7793, 0, VECTOR2(3, 1), VECTOR2() },
    { 7803, 0, VECTOR2(3, 0), VECTOR2() },
    { 7815, 2, VECTOR2(2, 0), VECTOR2(0, 0), VECTOR2(-1, 0) },
    { 7815, 2, VECTOR2(1, 0), VECTOR2(0, 0), VECTOR2(-1, 0) },
    { 7815, 2, VECTOR2(0, 0), VECTOR2(0, 0), VECTOR2(-1, 0) },
};


void crystallized_game_init()
{
    /*===== initialization =====*/
    crystallized_game_state = 0;
    music_timer = 4;
}

void crystallized_game_deinit()
{
}

void crystallized_game_update()
{
    switch (crystallized_game_state)
    {
    case 0:
        /*===== initialization =====*/

        crystallized_game_state += 1;
        note_count = sizeof(notes_cry) / sizeof(Note);

        /* fallthrough */

    case 1:
        /*===== parameter setting =====*/

        GameLib::setBlendMode(Blender::BS_ALPHA);

        music::load(MUSIC_CRY, L"./Data/Musics/crystallized.wav", 0.4f);

        music::play(MUSIC_CRY);

        grid_y = 0;
        grid_x = 0;

        for (int i = 0; i < note_count; i++) {
            notes_cry[i].hit = false;
        }

        result_note = Result_date{};
        result_cry.max_score = 1000 * note_count;

        crystallized_game_state += 1;
        fade_state = FADE_OUT_START;

        /* fallthrough */

    case 2:
        /*===== normal time =====*/

        debug::setString("perfect:%i", result_note.perfect);
        debug::setString("good:%i", result_note.good);
        debug::setString("miss:%i", result_note.miss);
        debug::setString("max_score:%i", result_note.score);
        debug::setString("max_combo:%i", result_note.combo);

        if (fade_state == FADE_IN) fade_in();
        if (fade_state == FADE_OUT_START) fade_out();

        music::update();

        //note_update(notes_cry, note_count);

        for (int i = 0; i < note_count; i++)
        {
            if (music_timer >= notes_cry[i].time - 60 && music_timer <= notes_cry[i].time + 60)
            {
                note_update(notes_cry, note_count);
            }
        }

        if (music_timer == 8200)
        {
            if (fade_state == FADE_NONE)
            {
                fade_state = FADE_IN;
            }
        }
        if (fade_state == FADE_DONE)
        {
            result_tag = RESULT_TUTO;
            next_scene = SCENE_RESULT; // Switch to next scene
        }

            music_timer++;
            player_update(true, true);
            
    }
}


void crystallized_game_render()
{
    GameLib::clear(0.0f, 0.0f, 0.0f);

    for (int i = 0; i < note_count; i++)
    {
        if (!notes_cry[i].hit && music_timer >= notes_cry[i].time - 50)
        {
            draw_note(notes_cry[i]);
        }
        else if (notes_cry[i].hit && music_timer <= notes_cry[i].time + 50)
        {
            draw_judge_effect(notes_cry[i]);
        }
    }

    rank_rend(result_cry, result_note, IN_GAME);

    primitive::rect
    (
        player_x, player_y,
        player_size, player_size,
        0, 0,
        0,
        1, 1, 1, 0.7f
    );


    // 縦線（column lines）
    for (int i = 0; i <= 4; ++i)
    {
        float x = start_x + i * cell_size;
        primitive::line(x, start_y, x, start_y + grid_size, 0.7f);
    }

    // 横線（row lines）
    for (int i = 0; i <= 4; ++i)
    {
        float y = start_y + i * cell_size;
        primitive::line(start_x, y, start_x + grid_size, y, 0.7f);
    }

    // Draw black rectangle with alpha
    primitive::rect(0, 0, SCREEN_W, SCREEN_H, 0, 0, 0, 0, 0, 0, fade_alpha);
}