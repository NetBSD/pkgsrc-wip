$NetBSD$

--- engine/lib/openal/NetBSD/AL/al.h.orig	2016-07-30 11:47:19.696497760 +0000
+++ engine/lib/openal/NetBSD/AL/al.h
@@ -0,0 +1,523 @@
+#ifndef __al_h_
+#define __al_h_
+
+/**
+ * OpenAL cross platform audio library
+ * Copyright (C) 1999-2000 by authors.
+ * This library is free software; you can redistribute it and/or
+ *  modify it under the terms of the GNU Library General Public
+ *  License as published by the Free Software Foundation; either
+ *  version 2 of the License, or (at your option) any later version.
+ *
+ * This library is distributed in the hope that it will be useful,
+ *  but WITHOUT ANY WARRANTY; without even the implied warranty of
+ *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
+ *  Library General Public License for more details.
+ *
+ * You should have received a copy of the GNU Library General Public
+ *  License along with this library; if not, write to the
+ *  Free Software Foundation, Inc., 59 Temple Place - Suite 330,
+ *  Boston, MA  02111-1307, USA.
+ * Or go to http://www.gnu.org/copyleft/lgpl.html
+ */
+#include <AL/altypes.h>
+
+#ifdef __cplusplus
+extern "C" {
+#endif
+
+#ifdef _WIN32
+#define ALAPI       __declspec(dllexport)
+#define ALAPIENTRY  __cdecl
+#define AL_CALLBACK 
+#else /* _WIN32 */
+#define ALAPI
+#define ALAPIENTRY
+#define AL_CALLBACK 
+#endif /* _WIN32 */
+
+#ifndef AL_NO_PROTOTYPES
+
+/**
+ * OpenAL Maintenance Functions
+ * State Management and Query.
+ * Error Handling.
+ * Extension Support.
+ */
+
+
+/** Renderer State management. */
+ALAPI void ALAPIENTRY alEnable( ALenum capability );
+
+ALAPI void ALAPIENTRY alDisable( ALenum capability ); 
+
+ALAPI ALboolean ALAPIENTRY alIsEnabled( ALenum capability ); 
+
+/** Application preferences for driver performance choices. */
+ALAPI void ALAPIENTRY alHint( ALenum target, ALenum mode );
+
+/** State retrieval. */
+ALAPI ALboolean ALAPIENTRY alGetBoolean( ALenum param );
+
+/** State retrieval. */
+ALAPI ALint ALAPIENTRY alGetInteger( ALenum param );
+
+/** State retrieval. */
+ALAPI ALfloat ALAPIENTRY alGetFloat( ALenum param );
+
+/** State retrieval. */
+ALAPI ALdouble ALAPIENTRY alGetDouble( ALenum param );
+
+/** State retrieval. */
+ALAPI void ALAPIENTRY alGetBooleanv( ALenum param, ALboolean* data );
+
+/** State retrieval. */
+ALAPI void ALAPIENTRY alGetIntegerv( ALenum param, ALint* data );
+
+/** State retrieval. */
+ALAPI void ALAPIENTRY alGetFloatv( ALenum param, ALfloat* data );
+
+/** State retrieval. */
+ALAPI void ALAPIENTRY alGetDoublev( ALenum param, ALdouble* data );
+
+/** State retrieval. */
+ALAPI const ALubyte* ALAPIENTRY alGetString( ALenum param );
+
+
+/**
+ * Error support.
+ * Obtain the most recent error generated in the AL state machine.
+ */
+ALAPI ALenum ALAPIENTRY alGetError( ALvoid );
+
+/** 
+ * Extension support.
+ * Obtain the address of a function (usually an extension)
+ *  with the name fname. All addresses are context-independent. 
+ */
+ALAPI ALboolean ALAPIENTRY alIsExtensionPresent( const ALubyte* fname );
+
+
+/** 
+ * Extension support.
+ * Obtain the address of a function (usually an extension)
+ *  with the name fname. All addresses are context-independent. 
+ */
+ALAPI void* ALAPIENTRY alGetProcAddress( const ALubyte* fname );
+
+
+/**
+ * Extension support.
+ * Obtain the integer value of an enumeration (usually an extension) with the name ename. 
+ */
+ALAPI ALenum ALAPIENTRY alGetEnumValue( const ALubyte* ename );
+
+
+
+
+
+
+/**
+ * LISTENER
+ * Listener is the sample position for a given context.
+ * The multi-channel (usually stereo) output stream generated
+ *  by the mixer is parametrized by this Listener object:
+ *  its position and velocity relative to Sources, within
+ *  occluder and reflector geometry.
+ */
+
+
+
+/**
+ *
+ * Listener Gain:  default 1.0f.
+ */
+ALAPI void ALAPIENTRY alListenerf( ALenum pname, ALfloat param );
+
+/**  
+ *
+ * Listener Position.
+ * Listener Velocity.
+ */
+ALAPI void ALAPIENTRY alListener3f( ALenum pname, ALfloat param1,
+             ALfloat param2,
+             ALfloat param3 ); 
+
+/**
+ *
+ * Listener Position:        ALfloat[3]
+ * Listener Velocity:        ALfloat[3]
+ * Listener Orientation:     ALfloat[6]  (forward and up vector).
+ */
+ALAPI void ALAPIENTRY alListenerfv( ALenum pname, ALfloat* param ); 
+
+/*
+ * Retrieve listener information.
+ */
+ALAPI void ALAPIENTRY alGetListeneri( ALenum pname, ALint* value );
+ALAPI void ALAPIENTRY alGetListenerf( ALenum pname, ALfloat* values );
+ALAPI void ALAPIENTRY alGetListenerfv( ALenum pname, ALfloat* values );
+
+/**
+ * SOURCE
+ * Source objects are by default localized. Sources
+ *  take the PCM data provided in the specified Buffer,
+ *  apply Source-specific modifications, and then
+ *  submit them to be mixed according to spatial 
+ *  arrangement etc.
+ */
+
+
+
+/** Create Source objects. */
+ALAPI void ALAPIENTRY alGenSources( ALsizei n, ALuint* sources ); 
+
+/** Delete Source objects. */
+ALAPI void ALAPIENTRY alDeleteSources( ALsizei n, ALuint* sources );
+
+/** Verify a handle is a valid Source. */ 
+ALAPI ALboolean ALAPIENTRY alIsSource( ALuint sid ); 
+
+
+/** Set an integer parameter for a Source object. */
+ALAPI void ALAPIENTRY alSourcei( ALuint sid, ALenum param, ALint value ); 
+ALAPI void ALAPIENTRY alSourcef( ALuint sid, ALenum param, ALfloat value ); 
+ALAPI void ALAPIENTRY alSource3f( ALuint sid, ALenum param, ALfloat v1, ALfloat v2, ALfloat v3 );
+ALAPI void ALAPIENTRY alSourcefv( ALuint sid, ALenum param, ALfloat* values ); 
+
+/** Get an integer parameter for a Source object. */
+ALAPI void ALAPIENTRY alGetSourcei( ALuint sid,  ALenum pname, ALint* value );
+ALAPI void ALAPIENTRY alGetSourcef( ALuint sid,  ALenum pname, ALfloat* value );
+ALAPI void ALAPIENTRY alGetSourcefv( ALuint sid, ALenum pname, ALfloat* values );
+
+ALAPI void ALAPIENTRY alSourcePlayv( ALuint ns, ALuint *ids );
+ALAPI void ALAPIENTRY alSourceStopv( ALuint ns, ALuint *ids );
+
+/** Activate a source, start replay. */
+ALAPI void ALAPIENTRY alSourcePlay( ALuint sid );
+
+/**
+ * Pause a source, 
+ *  temporarily remove it from the mixer list.
+ */
+ALAPI void ALAPIENTRY alSourcePause( ALuint sid );
+
+/**
+ * Stop a source,
+ *  temporarily remove it from the mixer list,
+ *  and reset its internal state to pre-Play.
+ * To remove a Source completely, it has to be
+ *  deleted following Stop, or before Play.
+ */
+ALAPI void ALAPIENTRY alSourceStop( ALuint sid );
+
+
+
+
+/**
+ * BUFFER
+ * Buffer objects are storage space for sample data.
+ * Buffers are referred to by Sources. There can be more than
+ *  one Source using the same Buffer data. If Buffers have
+ *  to be duplicated on a per-Source basis, the driver has to
+ *  take care of allocation, copying, and deallocation as well
+ *  as propagating buffer data changes.
+ */
+
+
+
+
+/** Buffer object generation. */
+ALAPI void ALAPIENTRY alGenBuffers( ALsizei n, ALuint* samples );
+
+ALAPI void ALAPIENTRY alDeleteBuffers( ALsizei n, ALuint* samples );
+
+
+ALAPI ALboolean ALAPIENTRY alIsBuffer( ALuint buffer );
+
+/**
+ * Specify the data to be filled into a buffer.
+ */
+ALAPI void ALAPIENTRY alBufferData( ALuint   buffer,
+         ALenum   format,
+                   ALvoid*    data,
+         ALsizei  size,
+         ALsizei  freq );
+
+
+/**
+ * Specify data to be filled into a looping buffer.
+ * This takes the current position at the time of the
+ *  call, and returns the number of samples written.
+ */
+ALsizei ALAPIENTRY alBufferAppendData( ALuint   buffer,
+                            ALenum   format,
+                            ALvoid*    data,
+                  ALsizei  size,
+                            ALsizei  freq );
+
+
+
+
+ALAPI void ALAPIENTRY alGetBufferi( ALuint buffer, ALenum param, ALint*   value );
+ALAPI void ALAPIENTRY alGetBufferf( ALuint buffer, ALenum param, ALfloat* value );
+
+
+
+
+
+/**
+ * Frequency Domain Filters are band filters.
+ *  Attenuation in Media (distance based)
+ *  Reflection Material
+ *  Occlusion Material (separating surface)
+ *
+ * Temporal Domain Filters:
+ *  Early Reflections
+ *  Late Reverb 
+ *
+ */
+
+
+
+
+/**
+ * EXTENSION: IASIG Level 2 Environment.
+ * Environment object generation.
+ * This is an EXTension that describes the Environment/Reverb
+ *  properties according to IASIG Level 2 specifications.
+ */
+
+
+
+
+
+/**
+ * Allocate n environment ids and store them in the array environs.
+ * Returns the number of environments actually allocated.
+ */
+ALAPI ALsizei ALAPIENTRY alGenEnvironmentIASIG( ALsizei n, ALuint* environs );
+
+ALAPI void ALAPIENTRY alDeleteEnvironmentIASIG( ALsizei n, ALuint* environs );
+
+ALAPI ALboolean ALAPIENTRY alIsEnvironmentIASIG( ALuint environ );
+
+ALAPI void ALAPIENTRY alEnvironmentiIASIG( ALuint eid, ALenum param, ALint value );
+
+ALAPI void ALAPIENTRY alEnvironmentfIASIG( ALuint eid, ALenum param, ALfloat value );
+
+
+
+
+#else /* AL_NO_PROTOTYPES */
+//
+//
+///** OpenAL Maintenance Functions */
+//
+//      void                         (*alEnable)( ALenum capability );
+//      void                         (*alDisable)( ALenum capability ); 
+//      ALboolean                    (*alIsEnabled)( ALenum capability ); 
+//      void            (*alHint)( ALenum target, ALenum mode );
+//      ALboolean                    (*alGetBoolean)( ALenum param );
+//      ALint                        (*alGetInteger)( ALenum param );
+//      ALfloat                      (*alGetFloat)( ALenum param );
+//      ALdouble                     (*alGetDouble)( ALenum param );
+//      void                         (*alGetBooleanv)( ALenum param,
+//                      ALboolean* data );
+//      void                         (*alGetIntegerv)( ALenum param,
+//                      ALint* data );
+//      void                         (*alGetFloatv)( ALenum param,
+//                      ALfloat* data );
+//      void                         (*alGetDoublev)( ALenum param,
+//                      ALdouble* data );
+//      const ALubyte*               (*GetString)( ALenum param );
+//      ALenum                       (*alGetError)( ALvoid );
+//
+//      /** 
+//       * Extension support.
+//       * Query existance of extension
+//       */
+//      ALboolean    (*alIsExtensionPresent)(const ALubyte* fname );
+//
+//      /** 
+//       * Extension support.
+//       * Obtain the address of a function (usually an extension)
+//       *  with the name fname. All addresses are context-independent. 
+//       */
+//      void*     (*alGetProcAddress)( const ALubyte* fname );
+//      
+//
+//      /**
+//       * Extension support.
+//       * Obtain the integer value of an enumeration (usually an extension) with the name ename. 
+//       */
+//      ALenum    (*alGetEnumValue)( const ALubyte* ename );
+//
+///**
+// * LISTENER
+// * Listener is the sample position for a given context.
+// * The multi-channel (usually stereo) output stream generated
+// *  by the mixer is parametrized by this Listener object:
+// *  its position and velocity relative to Sources, within
+// *  occluder and reflector geometry.
+// */
+//      /**
+//       *
+//       * Listener Gain:  default 1.0f.
+//       */
+//      void      (*alListenerf)( ALenum pname, ALfloat param );
+//
+//      /**  
+//       *
+//       * Listener Position.
+//       * Listener Velocity.
+//       */
+//      void      (*alListener3f)( ALenum pname,
+//             ALfloat param1, ALfloat param2, ALfloat param3); 
+//
+//      /**
+//       *
+//       * Listener Position:        ALfloat[3]
+//       * Listener Velocity:        ALfloat[3]
+//       * Listener Orientation:     ALfloat[6]  (forward and up vector).
+//       */
+//      void      (*alListenerfv)( ALenum pname, ALfloat* param ); 
+//
+///**
+// * SOURCE
+// * Source objects are by default localized. Sources
+// *  take the PCM data provided in the specified Buffer,
+// *  apply Source-specific modifications, and then
+// *  submit them to be mixed according to spatial 
+// *  arrangement etc.
+// */
+//
+//      /** Create Source objects. */
+//      void      (*alGenSources)( ALsizei n, ALuint* sources ); 
+//
+//      /** Delete Source objects. */
+//      void      (*alDeleteSources)( ALsizei n, ALuint* sources );
+//
+//      /** Verify a handle is a valid Source. */ 
+//      ALboolean (*alIsSource)( ALuint sid ); 
+//
+//      /** Set an integer parameter for a Source object. */
+//      void      (*alSourcei)( ALuint sid, ALenum param, ALint value); 
+//
+//      /** Set a float parameter for a Source object. */
+//      void      (*alSourcef)( ALuint sid, ALenum param, ALfloat value); 
+//
+//      /** Set a 3-float parameter for a Source object. */
+//      void      (*alSource3f)( ALuint sid, ALenum param,
+//             ALfloat v1, ALfloat v2, ALfloat v3 );
+//
+//      /** Set a float vector parameter for a Source object. */
+//      void      (*alSourcefv)( ALuint sid, ALenum param,
+//             ALfloat* values ); 
+//
+//      /** Get an integer parameter for a Source object. */
+//      void      (*alGetSourcei)( ALuint sid,
+//             ALenum pname, ALint* value );
+//      /** Get a float parameter for a Source object. */
+//      void      (*alGetSourcef)( ALuint sid,
+//             ALenum pname, ALfloat* value );
+//      /** Get a float vector parameter for a Source object. */
+//      void      (*alGetSourcefv)( ALuint sid,
+//             ALenum pname, ALfloat* values );
+//
+//      /** Activate a source, start replay. */
+//      void      (*alSourcePlay)( ALuint sid );
+//
+//      /**
+//       * Pause a source, 
+//       *  temporarily remove it from the mixer list.
+//       */
+//      void      (*alSourcePause)( ALuint sid );
+//
+//      /**
+//       * Stop a source,
+//       *  temporarily remove it from the mixer list,
+//       *  and reset its internal state to pre-Play.
+//       * To remove a Source completely, it has to be
+//       *  deleted following Stop, or before Play.
+//       */
+//      void      (*alSourceStop)( ALuint sid );
+//
+///**
+// * BUFFER
+// * Buffer objects are storage space for sample data.
+// * Buffers are referred to by Sources. There can be more than
+// *  one Source using the same Buffer data. If Buffers have
+// *  to be duplicated on a per-Source basis, the driver has to
+// *  take care of allocation, copying, and deallocation as well
+// *  as propagating buffer data changes.
+// */
+//
+//      /** Buffer object generation. */
+//      void      (*alGenBuffers)( ALsizei n, ALuint* samples );
+//      void      (*alDeleteBuffers)( ALsizei n, ALuint* samples );
+//      ALboolean    (*alIsBuffer)( ALuint buffer );
+//
+//      /**
+//       * Specify the data to be filled into a buffer.
+//       */
+//      void      (*alBufferData)( ALuint   buffer,
+//                  ALenum   format,
+//                            ALvoid*    data,
+//                  ALsizei  size,
+//                  ALsizei  freq );
+//
+//      /**
+//       * Specify data to be filled into a looping buffer.
+//       * This takes the current position at the time of the
+//       *  call, and returns the number of samples written.
+//       */
+//      ALsizei      (*alBufferAppendData)( ALuint   buffer,
+//                                     ALenum   format,
+//                                     ALvoid*    data,
+//                           ALsizei  size,
+//                                     ALsizei  freq );
+//      void      (*alGetBufferi)( ALuint buffer,
+//                ALenum param, ALint*   value );
+//      void      (*alGetBufferf)( ALuint buffer,
+//                ALenum param, ALfloat* value );
+//
+///**
+// * EXTENSION: IASIG Level 2 Environment.
+// * Environment object generation.
+// * This is an EXTension that describes the Environment/Reverb
+// *  properties according to IASIG Level 2 specifications.
+// */
+//      /**
+//       * Allocate n environment ids and store them in the array environs.
+//       * Returns the number of environments actually allocated.
+//       */
+//      ALsizei      (*alGenEnvironmentIASIG)( ALsizei n, ALuint* environs );
+//      void      (*alDeleteEnvironmentIASIG)(ALsizei n,
+//                   ALuint* environs);
+//      ALboolean    (*alIsEnvironmentIASIG)( ALuint environ );
+//      void      (*alEnvironmentiIASIG)( ALuint eid,
+//                ALenum param, ALint value );
+//      void      (*alEnvironmentfIASIG)( ALuint eid,
+//                ALenum param, ALuint value );
+//
+///**
+// * Frequency Domain Filters are band filters.
+// *  Attenuation in Media (distance based)
+// *  Reflection Material
+// *  Occlusion Material (separating surface)
+// *
+// * Temporal Domain Filters:
+// *  Early Reflections
+// *  Late Reverb 
+// *
+// */
+//
+#endif /* AL_NO_PROTOTYPES */
+
+
+#ifdef __cplusplus
+}  /* extern "C" */
+#endif
+
+#endif /* __al_h_ */
