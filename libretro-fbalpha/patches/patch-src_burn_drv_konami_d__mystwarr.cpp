$NetBSD$

Backport changes from master, includes fix for sprite flickering.

--- src/burn/drv/konami/d_mystwarr.cpp.orig	2017-07-13 03:39:54.000000000 +0000
+++ src/burn/drv/konami/d_mystwarr.cpp
@@ -7,7 +7,8 @@
 			background layer #2 on intro (bad guy on motorcycle), bottom clipped??
 
 		metamorphic force
-			background in lava level is too fast. (irq?)
+			level 1 boss "fire" circle around boss priority issue
+		    background in lava level is too fast. (irq?)
 
 		martial champ
 		1: missing graphics in intro & title screens. On blank screens
@@ -80,7 +81,7 @@ static UINT8 DrvJoy4[16];
 static UINT8 DrvJoy5[16];
 static UINT8 DrvReset;
 static UINT16 DrvInputs[6];
-static UINT8 DrvDips[1];
+static UINT8 DrvDips[2];
 
 static INT32 sound_nmi_enable = 0;
 static UINT8 sound_control = 0;
@@ -101,25 +102,25 @@ static struct BurnInputInfo MystwarrInpu
 	{"P1 Button 2",		BIT_DIGITAL,	DrvJoy3 + 5,	"p1 fire 2"},
 	{"P1 Button 3",		BIT_DIGITAL,	DrvJoy3 + 6,	"p1 fire 3"},
 
-	{"P2 Coin",		BIT_DIGITAL,	DrvJoy1 + 1,	"p2 coin"},
-	{"P2 Start",		BIT_DIGITAL,	DrvJoy4 + 7,	"p2 start"},
-	{"P2 Up",		BIT_DIGITAL,	DrvJoy4 + 2,	"p2 up"},
-	{"P2 Down",		BIT_DIGITAL,	DrvJoy4 + 3,	"p2 down"},
-	{"P2 Left",		BIT_DIGITAL,	DrvJoy4 + 0,	"p2 left"},
-	{"P2 Right",		BIT_DIGITAL,	DrvJoy4 + 1,	"p2 right"},
-	{"P2 Button 1",		BIT_DIGITAL,	DrvJoy4 + 4,	"p2 fire 1"},
-	{"P2 Button 2",		BIT_DIGITAL,	DrvJoy4 + 5,	"p2 fire 2"},
-	{"P2 Button 3",		BIT_DIGITAL,	DrvJoy4 + 6,	"p2 fire 3"},
+	{"P2 Coin",		BIT_DIGITAL,	DrvJoy1 + 2,	"p2 coin"},
+	{"P2 Start",		BIT_DIGITAL,	DrvJoy3 + 15,	"p2 start"},
+	{"P2 Up",		BIT_DIGITAL,	DrvJoy3 + 10,	"p2 up"},
+	{"P2 Down",		BIT_DIGITAL,	DrvJoy3 + 11,	"p2 down"},
+	{"P2 Left",		BIT_DIGITAL,	DrvJoy3 + 8,	"p2 left"},
+	{"P2 Right",		BIT_DIGITAL,	DrvJoy3 + 9,	"p2 right"},
+	{"P2 Button 1",		BIT_DIGITAL,	DrvJoy3 + 12,	"p2 fire 1"},
+	{"P2 Button 2",		BIT_DIGITAL,	DrvJoy3 + 13,	"p2 fire 2"},
+	{"P2 Button 3",		BIT_DIGITAL,	DrvJoy3 + 14,	"p2 fire 3"},
 
-	{"P3 Coin",		BIT_DIGITAL,	DrvJoy1 + 2,	"p3 coin"},
-	{"P3 Start",		BIT_DIGITAL,	DrvJoy3 + 15,	"p3 start"},
-	{"P3 Up",		BIT_DIGITAL,	DrvJoy3 + 10,	"p3 up"},
-	{"P3 Down",		BIT_DIGITAL,	DrvJoy3 + 11,	"p3 down"},
-	{"P3 Left",		BIT_DIGITAL,	DrvJoy3 + 8,	"p3 left"},
-	{"P3 Right",		BIT_DIGITAL,	DrvJoy3 + 9,	"p3 right"},
-	{"P3 Button 1",		BIT_DIGITAL,	DrvJoy3 + 12,	"p3 fire 1"},
-	{"P3 Button 2",		BIT_DIGITAL,	DrvJoy3 + 13,	"p3 fire 2"},
-	{"P3 Button 3",		BIT_DIGITAL,	DrvJoy3 + 14,	"p3 fire 3"},
+	{"P3 Coin",		BIT_DIGITAL,	DrvJoy1 + 1,	"p3 coin"},
+	{"P3 Start",		BIT_DIGITAL,	DrvJoy4 + 7,	"p3 start"},
+	{"P3 Up",		BIT_DIGITAL,	DrvJoy4 + 2,	"p3 up"},
+	{"P3 Down",		BIT_DIGITAL,	DrvJoy4 + 3,	"p3 down"},
+	{"P3 Left",		BIT_DIGITAL,	DrvJoy4 + 0,	"p3 left"},
+	{"P3 Right",		BIT_DIGITAL,	DrvJoy4 + 1,	"p3 right"},
+	{"P3 Button 1",		BIT_DIGITAL,	DrvJoy4 + 4,	"p3 fire 1"},
+	{"P3 Button 2",		BIT_DIGITAL,	DrvJoy4 + 5,	"p3 fire 2"},
+	{"P3 Button 3",		BIT_DIGITAL,	DrvJoy4 + 6,	"p3 fire 3"},
 
 	{"P4 Coin",		BIT_DIGITAL,	DrvJoy1 + 3,	"p4 coin"},
 	{"P4 Start",		BIT_DIGITAL,	DrvJoy4 + 15,	"p4 start"},
@@ -133,6 +134,7 @@ static struct BurnInputInfo MystwarrInpu
 
 	{"Reset",		BIT_DIGITAL,	&DrvReset,	"reset"},
 	{"Dip A",		BIT_DIPSWITCH,	DrvDips + 0,	"dip"},
+	{"Dip B",		BIT_DIPSWITCH,	DrvDips + 1,	"dip"},
 };
 
 STDINPUTINFO(Mystwarr)
@@ -328,6 +330,7 @@ STDINPUTINFO(Martchmp)
 static struct BurnDIPInfo MystwarrDIPList[]=
 {
 	{0x25, 0xff, 0xff, 0xe4, NULL			},
+	{0x26, 0xff, 0xff, 0x00, NULL			},
 
 	{0   , 0xfe, 0   ,    2, "Service Mode"		},
 	{0x25, 0x01, 0x04, 0x04, "Off"			},
@@ -344,6 +347,10 @@ static struct BurnDIPInfo MystwarrDIPLis
 	{0   , 0xfe, 0   ,    2, "Number of Players"	},
 	{0x25, 0x01, 0x40, 0x00, "4"			},
 	{0x25, 0x01, 0x40, 0x40, "2"			},
+
+	{0   , 0xfe, 0   ,    2, "Debug Alpha Mode (debug console/logfile)"		},
+	{0x26, 0x01, 0x01, 0x00, "Off"			},
+	{0x26, 0x01, 0x01, 0x01, "On"			},
 };
 
 STDDIPINFO(Mystwarr)
@@ -1681,11 +1688,27 @@ static UINT8 __fastcall mystwarr_sound_r
 }
 
 //--------------------------------------------------------------------------------------------------------------
+static INT32 superblend = 0;
+static INT32 oldsuperblend = 0;
+static INT32 superblendoff = 0;
 
 static void mystwarr_tile_callback(INT32 layer, INT32 *code, INT32 *color, INT32 *flags)
 {
-	if (layer == 1 && (*code & 0xff00) + (*color) == 0x4101) *flags = (*flags)|(0x808000); //* water hack
+	if (layer == 1) {
+		/**/ if ((*code & 0xff00) + (*color) == 0x4101) superblend++; // water
+		else if ((*code & 0xff00) + (*color) == 0xA30D) superblend++; // giant cargo plane
+		else if ((*code & 0xff00) + (*color) == 0xA40D) superblend++; // giant cargo plane
+		else if ((*code & 0xff00) + (*color) == 0xA50D) superblend++; // giant cargo plane
+		else if ((*code & 0xff00) + (*color) == 0xFA01) superblend++; // intro "but behind the scenes..." part 1/x
+		else if ((*code & 0xff00) + (*color) == 0xFA05) superblend++; // intro "but behind the scenes..." part 2
+		else if ((*code & 0xff00) + (*color) == 0xFB01) superblend++; // part 3.
+		else if ((*code & 0xff00) + (*color) == 0xFB05) superblend++; // part 4.
+		else if ((*code & 0xff00) + (*color) == 0xFC05) superblend++; // part 5.
+		else if ((*code & 0xff00) + (*color) == 0xD001) superblend++; // Title Screen
+		else if ((*code & 0xff00) + (*color) == 0xC700) superblendoff++; // End Boss death scene (anti superblend)
 
+		//if (counter) bprintf(0, _T("%X %X (%X), "), *code, *color, (*code & 0xff00) + (*color)); /* save this! -dink */
+	}
 	*color = layer_colorbase[layer] | ((*color >> 1) & 0x1e);
 }
 
@@ -1809,6 +1832,10 @@ static INT32 DrvDoReset()
 	oinprion = 0;
 	sound_nmi_enable = 0;
 
+	superblend = 0; // for mystwarr alpha tile count
+	oldsuperblend = 0;
+	superblendoff = 0;
+
 	return 0;
 }
 
@@ -1977,13 +2004,13 @@ static INT32 MystwarrInit()
 
 	K056832Init(DrvGfxROM0, DrvGfxROMExp0, 0x400000, mystwarr_tile_callback);
 	K056832SetGlobalOffsets(24, 16);
-	K056832SetLayerOffsets(0, -2-4, 0);
-	K056832SetLayerOffsets(1,  0-4, 0);
-	K056832SetLayerOffsets(2,  2-4, 0);
-	K056832SetLayerOffsets(3,  3-4, 0);
+	K056832SetLayerOffsets(0, -2-3, 0);
+	K056832SetLayerOffsets(1,  0-3, 0);
+	K056832SetLayerOffsets(2,  2-3, 0);
+	K056832SetLayerOffsets(3,  3-3, 0);
 
 	K053247Init(DrvGfxROM1, DrvGfxROMExp1, 0x7fffff, mystwarr_sprite_callback, 3);
-	K053247SetSpriteOffset(-24-48, -16-24);
+	K053247SetSpriteOffset(-25-48, -15-24);
 	K053247SetBpp(5);
 
 	konamigx_mixer_init(0);
@@ -2306,6 +2333,7 @@ static INT32 MartchmpInit()
 	K053247SetBpp(5);
 
 	konamigx_mixer_init(0);
+	K054338_invert_alpha(0);
 
 	SekInit(0, 0x68000);
 	SekOpen(0);
@@ -2458,7 +2486,6 @@ static INT32 GaiapolisInit()
 	K053247SetSpriteOffset(7+(-24-79), -16-24);
 
 	konamigx_mixer_init(0);
-//	K054338_invert_alpha(0); // otherwise alpha blended roz is too light - sept.2.2016 - this breaks the "elevator/going down" level
 
 	SekInit(0, 0x68000);
 	SekOpen(0);
@@ -2698,6 +2725,7 @@ static INT32 DrvExit()
 	BurnFree (AllMem);
 	if (pMystwarrRozBitmap) {
 		BurnFree (pMystwarrRozBitmap);
+		pMystwarrRozBitmap = NULL;
 	}
 	return 0;
 }
@@ -2731,7 +2759,45 @@ static INT32 DrvDraw()
 	if (nGame == 1) { // mystwarr
 		blendmode = 0;
 		cbparam = 0; // ?
+
+		{ // "Superblend and the Survival of Alpha (in Mystwarr)"
+			switch (Drv68KRAM[0x2335]) {
+				case 0x0A:
+				case 0x11:
+				case 0x18: { // alpha on for sure, except endboss death scene (see: superblendoff)
+					superblend = 0xfff;
+					break;
+				}
+
+				case 0x09:
+				case 0x10:
+				case 0x12:
+			    default: { // alpha off, but only if tilecount isn't rising
+					if (superblend < oldsuperblend) {
+						superblend = 0;
+					}
+					break;
+				}
+			}
+
+			if ((superblend || oldsuperblend) && !superblendoff) {
+				blendmode = (1 << 16 | GXMIX_BLEND_FORCE) << 2; // using "|| oldsuperblend" for 1 frame latency, to avoid flickers on the water level when he gets "flushed" into the boss part
+			}
+
+			if (DrvDips[1] & 1) // debug alpha
+				bprintf(0, _T("%X %X (%X), "), superblend, oldsuperblend, Drv68KRAM[0x2335]);
+
+			oldsuperblend = superblend;
+			if (superblend) superblend = 1;
+
+			superblendoff = 0; // frame-based.
+		}
+
 		sprite_colorbase = K055555GetPaletteIndex(4)<<5;
+		konamigx_mixer(enable_sub, 0, 0, 0, blendmode, 0, 0);
+		KonamiBlendCopy(DrvPalette);
+
+		return 0;
 	}
 
 	if (nGame == 2 || nGame == 3) { // viostorm / metamrph
@@ -2795,7 +2861,6 @@ static INT32 DrvFrame()
 	ZetNewFrame();
 
 	INT32 nInterleave = 60;
-	INT32 nSoundBufferPos = 0;
 	INT32 nCyclesTotal[2] = { 16000000 / 60, 8000000 / 60 };
 	INT32 nCyclesDone[2] = { 0, 0 };
 
@@ -2805,19 +2870,14 @@ static INT32 DrvFrame()
 	for (INT32 i = 0; i < nInterleave; i++) {
 		INT32 nNext, nCyclesSegment;
 
-		nNext = (i + 1) * nCyclesTotal[0] / nInterleave;
-		nCyclesSegment = nNext - nCyclesDone[0];
-		nCyclesSegment = SekRun(nCyclesSegment);
-		nCyclesDone[0] += nCyclesSegment;
-
 		if (nGame == 1)
 		{
 			if (mw_irq_control & 1)
 			{
 				if (i == 0)
 					SekSetIRQLine(4, CPU_IRQSTATUS_AUTO);
-	
-				if (i == ((nInterleave * 240)/256))
+
+				if (i == ((nInterleave * (240+10))/256)) // +10 otherwise flickers on char.selection screen (mystwarr)
 					SekSetIRQLine(2, CPU_IRQSTATUS_AUTO);
 			}
 		}
@@ -2852,6 +2912,12 @@ static INT32 DrvFrame()
 				SekSetIRQLine(5, CPU_IRQSTATUS_AUTO);
 		}
 
+		nNext = (i + 1) * nCyclesTotal[0] / nInterleave;
+		nCyclesSegment = nNext - nCyclesDone[0];
+		nCyclesSegment = SekRun(nCyclesSegment);
+		nCyclesDone[0] += nCyclesSegment;
+
+
 		nNext = (i + 1) * nCyclesTotal[1] / nInterleave;
 		nCyclesSegment = nNext - nCyclesDone[1];
 		nCyclesSegment = ZetRun(nCyclesSegment);
@@ -2860,25 +2926,12 @@ static INT32 DrvFrame()
 		if ((i % (nInterleave / 8)) == ((nInterleave / 8) - 1)) {// && sound_nmi_enable && sound_control) { // iq_132
 			ZetNmi();
 		}
-
-		if (pBurnSoundOut) {
-			INT32 nSegmentLength = nBurnSoundLen / nInterleave;
-			INT16* pSoundBuf = pBurnSoundOut + (nSoundBufferPos << 1);
-			memset(pSoundBuf, 0, nSegmentLength * 2 * 2);
-			K054539Update(0, pSoundBuf, nSegmentLength);
-			K054539Update(1, pSoundBuf, nSegmentLength);
-			nSoundBufferPos += nSegmentLength;
-		}
 	}
 
 	if (pBurnSoundOut) {
-		INT32 nSegmentLength = nBurnSoundLen - nSoundBufferPos;
-		INT16* pSoundBuf = pBurnSoundOut + (nSoundBufferPos << 1);
-		if (nSegmentLength) {
-			memset(pSoundBuf, 0, nSegmentLength * 2 * 2);
-			K054539Update(0, pSoundBuf, nSegmentLength);
-			K054539Update(1, pSoundBuf, nSegmentLength);
-		}
+		memset (pBurnSoundOut, 0, nBurnSoundLen * 2 * 2);
+		K054539Update(0, pBurnSoundOut, nBurnSoundLen);
+		K054539Update(1, pBurnSoundOut, nBurnSoundLen);
 	}
 
 	ZetClose();
@@ -2891,7 +2944,7 @@ static INT32 DrvFrame()
 	return 0;
 }
 
-static INT32 DrvScan(INT32 nAction,INT32 *pnMin)
+static INT32 DrvScan(INT32 nAction, INT32 *pnMin)
 {
 	struct BurnArea ba;
 
@@ -2924,6 +2977,9 @@ static INT32 DrvScan(INT32 nAction,INT32
 		SCAN_VAR(cbparam);
 		SCAN_VAR(oinprion);
 		SCAN_VAR(z80_bank);
+		SCAN_VAR(superblend);
+		SCAN_VAR(oldsuperblend);
+		SCAN_VAR(superblendoff);
 	}
 
 	if (nAction & ACB_WRITE) {
