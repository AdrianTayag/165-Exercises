// http://www.phy.mtu.edu/~suits/notefreqs.html

#define  P62 500
#define  P125 125000
#define  P250 250000
#define  P375 375000
#define  P500 500000
#define  P750 750000
#define  P1000   1000000
#define  P2000   2000000
#define  P3000   3000000

#define  NULL 0
#define  B3b  233
#define  B3   247
#define  C4   261
#define  C4u  277
#define  D4b  277
#define  D4   294
#define  D4u  311
#define  E4b  311
#define  E4   330
#define  F4   349
#define  F4u  370
#define  G4b  370
#define  G4   392
#define  G4u  415
#define  A4b  415
#define  A4   440
#define  A4u  466
#define  B4b  466
#define  B4   494

#define  C5   523
#define  C5u  554
#define  D5b  554
#define  D5   587
#define  D5u  622
#define  E5b  622
#define  E5   659
#define  F5   698
#define  F5u  740
#define  G5b  740
#define  G5   784
#define  G5u  831
#define  A5b  831
#define  A5   880
#define  A5u  932
#define  B5b  932
#define  B5   987

#define  C6   1047
#define  C6u  1109
#define  D6b  1109
#define  D6   1175



	uint16_t tone[17] = {E4b, 0, E4b, 0, E4b, 0, B3b, 0, E4b, 0, G4, 0, F4, 0, G4, G4, 0};

	uint16_t tone2[30] = {G4, 0, F4u, 0, G4, G4, G4, 0, D4, 0, B4, 0, A4, A4, 0, G4, 0, E4, 0, E4, 0, E4, 0, E4, 0, G4, 0, G4, G4, 0};

	uint32_t tone3[80] = {G5, 0, G5, 0, D6, 0, A5, 0, A5, 0, G5, 0, A5, 0, B5, 0, B5, B5, 0, G5, 0, D6, 0, A5, 0, A5, 0, G5, 0, A5, 0, B5, 0, B5, 0, G5, 0, G5, 0, G5, 0, B5, 0, G5, 0, A5, 0, G5, 0, B5, 0, G5, 0, A5, 0, G5, 0, B5, 0, G5, 0, A5, 0};	//63

	uint32_t tone4[90] =   {C4, 0, C4, 0, G4, 0, G4, 0, A4, 0, A4, 0, G4, 0, F4, 0, F4, 0, E4, 0, E4, 0, D4, 0, D4, 0, C4, 0,	G4, 0, G4, 0, F4, 0, F4, 0, E4, 0, E4, 0, D4, 0, G4, 0, G4, 0, F4, 0, F4, 0, E4, 0, E4, 0, D4, 0, C4, 0, C4, 0, G4, 0, G4, 0, A4, 0, A4, 0, G4, 0, F4, 0, F4, 0, E4, 0, E4, 0, D4, 0, D4, 0, C4, 0};

	uint32_t tone5[180] = {C4, 0, E4, 0, A4, 0, B4, 0, E4, 0, C4, 0, E4, 0, C5, 0, E4, 0, C4, 0, E4, 0, B4, 0, A4, 0, E4, 0, C4, 0, A4, 0, C4, 0, E4, 0, A4, A4, 0, E4, 0, C4, 0, E4, 0, B3, 0, C4, 0, C4, 0, C4, 0, E4, 0, A4, 0, B4, 0, E4, 0, C4, 0, B4, 0, C5, 0, E4, 0, C4, 0, E4, 0, B4, 0, A4, 0, E4, 0, C4, 0, B4, 0, C4, 0, E4, 0, A4, A4, 0, E4, 0, C4, 0, E4, 0, B3b, 0, B3, 0, B3, 0, D4, 0, D4, 0, E4, 0, F4u, 0, F4, 0, A4, 0, C4, 0, G4, 0, F4, 0, E4, 0, D4, 0, E4, 0, E4, 0, D4, 0, B3, 0, D4, 0, G4, 0, G4, 0, F4u, 0, F4, 0};
	uint32_t length[17] = {P250, P62, P250, P62, P250, P62, P250, P62, P250, P62, P250, P62, P500, P62, P2000, P250, P250};

	uint32_t length2[30] = {P250, P62, P250, P62, P250, P500, P250, P62, P250, P62, P250, P62, P250, P500, P62, P250, P62, P250, P62, P250, P62, P500, P62, P500, P62, P250, P62, P250, P500, P500};

	uint32_t length3[80] = {P250, P62, P250, P62, P250, P62, P500, P62, P125, P62, P125, P62, P125, P62, P125, P62, P250, P250, P62, P250, P62, P250, P62, P500, P62, P125, P62, P125, P62, P125, P62, P125, P62, P125, P62, P125, P62, P250, P62, P125, P62, P250, P62, P125, P62, P250, P250, P125, P62,P250, P62, P125, P62, P250, P250, P125, P62,P250, P62, P125, P62, P250, P250};

	uint32_t length4[90] = {P500, P62, P500, P62, P500, P62, P500, P62, P500, P62, P500, P62, P1000, P62, P500, P62, P500, P62, P500, P62, P500, P62, P500, P62, P500, P62, P1000, P62, P500, P62, P500, P62, P500, P62, P500, P62, P500, P62, P500, P62, P1000, P62};

	uint32_t length5[180] = {P250, P62, P250, P62, P250, P62, P250, P62, P250, P62, P250, P62, P250, P62, P250, P62, P250, P62, P250, P62, P250, P62, P250, P62, P250, P62, P250, P62, P250, P62, P250, P62, P250, P62, P250, P62, P250, P250, P62, P250, P62, P250, P62, P250, P62, P250, P62, P250, P62, P500, P250, P250, P62, P250, P62, P250, P62, P250, P62, P250, P62, P250, P62, P250, P62, P250, P62, P250, P62, P250, P62, P250, P62, P250, P62, P250, P62, P250, P62, P250, P62, P250, P62, P250, P62, P250, P62, P250, P250, P62, P250, P62, P250, P62, P250, P62, P250, P62, P250, P62, P500, P500, P500, P500, P250, P250, P62, P750, P62, P250, P62, P250, P62, P250, P62, P250, P62, P250, P62, P500, P250, P250, P62, P500, P250, P250, P62, P250, P62, P250, P62, P250, P62, P250, P62, P250, P62, P250, P62, P1000, P500}
