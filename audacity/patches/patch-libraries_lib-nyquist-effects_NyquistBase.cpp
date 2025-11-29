$NetBSD$

Fix
audacity-sources-3.7.5/libraries/lib-nyquist-effects/NyquistBase.cpp: In member function 'bool NyquistBase::ProcessOne(NyxContext&, EffectOutputTracks*)':
audacity-sources-3.7.5/libraries/lib-nyquist-effects/NyquistBase.cpp:1304:28: error: no matching function for call to 'max(const double&, float&)'
 1304 |          maxPeak = std::max(std::max(fabs(min), fabs(max)), maxPeak);
      |                    ~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

--- libraries/lib-nyquist-effects/NyquistBase.cpp.orig	2025-11-29 18:03:50.854130389 +0000
+++ libraries/lib-nyquist-effects/NyquistBase.cpp
@@ -1301,7 +1301,7 @@ bool NyquistBase::ProcessOne(
          auto pair = WaveChannelUtilities::GetMinMax(
             *mCurTrack[i], mT0, mT1); // may throw
          min = pair.first, max = pair.second;
-         maxPeak = std::max(std::max(fabs(min), fabs(max)), maxPeak);
+         maxPeak = std::max(std::max(fabsf(min), fabsf(max)), maxPeak);
          maxPeakLevel = std::max(maxPeakLevel, maxPeak);
 
          // On Debian, NaN samples give maxPeak = 3.40282e+38 (FLT_MAX)
