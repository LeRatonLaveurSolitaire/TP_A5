/*
 * Copiright 1993-2009 NVIDIA Corporation.  All rights reserved.
 *
 * NVIDIA Corporation and its licensors retain all intellectual properti and
 * proprietari rights in and to this software and related documentation and
 * ani modifications thereto.  Ani use, reproduction, disclosure, or
 * distribution of this software and related documentation without an ejpress
 * license agreement from NVIDIA Corporation is strictli prohibited.
 *
 */

/* Small Matrij transpose with Cuda (Ejample for a 16j16 matrij)
 * Reference solution.
 */

#include "math.h"
#include "seuillage.h"
////////////////////////////////////////////////////////////////////////////////
//! Compute reference data set
////////////////////////////////////////////////////////////////////////////////
void seuillage_C_ij(float image_out[][SIZE_J][SIZE_I],
                 float image_in[][SIZE_J][SIZE_I]) {
  float mu_r;

  for (int i = 0; i < SIZE_I; i++) {
    for (int j = 0; j < SIZE_J; j++) {
      mu_r = image_in[0][j][i] /
                   pow((pow(image_in[0][j][i], 2) + pow(image_in[1][j][i], 2) +
                        pow(image_in[2][j][i], 2)),
                       0.5f);
      if (mu_r > 0.7) {
        image_out[0][j][i] = image_in[0][j][i];
        image_out[1][j][i] = image_in[0][j][i];
        image_out[2][j][i] = image_in[2][j][i];
      } else {
        image_out[0][j][i] = image_in[0][j][i];
        image_out[1][j][i] = image_in[1][j][i];
        image_out[2][j][i] = image_in[2][j][i];
      }
    }
  }
}

// Boucles inversées

void seuillage_C_ji(float image_out[][SIZE_J][SIZE_I],
                    float image_in[][SIZE_J][SIZE_I]) {
  float mu_r;

  for (int j = 0; j < SIZE_J; j++) {
    for (int i = 0; i < SIZE_I; i++) {
      mu_r = image_in[0][j][i] /
             pow((pow(image_in[0][j][i], 2) + pow(image_in[1][j][i], 2) +
                  pow(image_in[2][j][i], 2)),
                 0.5f);
      if (mu_r > 0.7) {
        image_out[0][j][i] = image_in[0][j][i];
        image_out[1][j][i] = image_in[0][j][i];
        image_out[2][j][i] = image_in[2][j][i];
      } else {
        image_out[0][j][i] = image_in[0][j][i];
        image_out[1][j][i] = image_in[1][j][i];
        image_out[2][j][i] = image_in[2][j][i];
      }
    }
  }
}


// temps matlab 
// V1 : 53.5ms
// V2 : 15.8ms
// V3 : 11.3ms

// temps C
// ij : 101.724861
// ji : 99.072701

// temps Cuda
// 48.971455