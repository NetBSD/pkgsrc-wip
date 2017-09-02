$NetBSD$

https://bugs.openmw.org/issues/3904

--- src/osg/Texture.cpp.orig	2015-06-10 16:47:15.000000000 +0000
+++ src/osg/Texture.cpp
@@ -69,7 +69,9 @@ struct InternalPixelRelations
     GLenum type;
 };
 
+
 InternalPixelRelations sizedInternalFormats[] = {
+
       { GL_R8UI                                , GL_RED_INTEGER_EXT  , GL_UNSIGNED_BYTE                             }
     , { GL_R8I                                 , GL_RED_INTEGER_EXT  , GL_BYTE                                      }
     , { GL_R16UI                               , GL_RED_INTEGER_EXT  , GL_UNSIGNED_SHORT                            }
@@ -99,21 +101,10 @@ InternalPixelRelations sizedInternalForm
     , { GL_RGBA32I_EXT                         , GL_RGBA_INTEGER_EXT , GL_INT                                       }
     , { GL_RGBA32UI_EXT                        , GL_RGBA_INTEGER_EXT , GL_UNSIGNED_INT                              }
 
-    , { GL_R8_SNORM                            , GL_RED              , GL_BYTE                                      }
-    , { GL_R16_SNORM                           , GL_RED              , GL_SHORT                                     }
-    , { GL_RG8_SNORM                           , GL_RG               , GL_BYTE                                      }
-    , { GL_RG16_SNORM                          , GL_RG               , GL_SHORT                                     }
-    , { GL_RGB8_SNORM                          , GL_RGB              , GL_BYTE                                      }
-    , { GL_RGB16_SNORM                         , GL_RGB              , GL_SHORT                                     }
-    , { GL_RGBA8_SNORM                         , GL_RGBA             , GL_BYTE                                      }
-
-    , { GL_SRGB8                               , GL_RGB              , GL_UNSIGNED_BYTE                             }
-    , { GL_SRGB8_ALPHA8                        , GL_RGBA             , GL_UNSIGNED_BYTE                             }
-
     , { GL_R8                                  , GL_RED              , GL_UNSIGNED_BYTE                             }
     , { GL_R16F                                , GL_RED              , GL_HALF_FLOAT                                }
-    , { GL_R16F                                , GL_RED              , GL_FLOAT                                     }
     , { GL_R32F                                , GL_RED              , GL_FLOAT                                     }
+    , { GL_R16F                                , GL_RED              , GL_FLOAT                                     }
     , { GL_RG8                                 , GL_RG               , GL_UNSIGNED_BYTE                             }
     , { GL_RG16F                               , GL_RG               , GL_HALF_FLOAT                                }
     , { GL_RG16F                               , GL_RG               , GL_FLOAT                                     }
@@ -125,10 +116,10 @@ InternalPixelRelations sizedInternalForm
     , { GL_RGB4                                , GL_RGB              , GL_UNSIGNED_SHORT_4_4_4_4_REV                }
     , { GL_RGB5                                , GL_RGB              , GL_UNSIGNED_SHORT_5_5_5_1                    }
     , { GL_RGB5                                , GL_RGB              , GL_UNSIGNED_SHORT_1_5_5_5_REV                }
+    , { GL_RGB8                                , GL_RGB              , GL_UNSIGNED_BYTE                             }
     , { GL_RGB565                              , GL_RGB              , GL_UNSIGNED_BYTE                             }
     , { GL_RGB565                              , GL_RGB              , GL_UNSIGNED_SHORT_5_6_5                      }
     , { GL_RGB565                              , GL_RGB              , GL_UNSIGNED_SHORT_5_6_5_REV                  }
-    , { GL_RGB8                                , GL_RGB              , GL_UNSIGNED_BYTE                             }
  // , { GL_RGB9_E5                             , GL_RGB              , GL_UNSIGNED_INT_9_9_9_5,                     }
  // , { GL_RGB9_E5                             , GL_RGB              , GL_UNSIGNED_INT_5_9_9_9_REV,                 }
  // , { GL_RGB9_E5                             , GL_RGB              , GL_HALF_FLOAT                                }
@@ -140,24 +131,36 @@ InternalPixelRelations sizedInternalForm
     , { GL_RGB10                               , GL_RGB              , GL_UNSIGNED_INT_10_10_10_2                   }
     , { GL_RGB12                               , GL_RGB              , GL_UNSIGNED_SHORT                            }
     , { GL_RGB16F_ARB                          , GL_RGB              , GL_HALF_FLOAT                                }
-    , { GL_RGB16F_ARB                          , GL_RGB              , GL_FLOAT                                     }
     , { GL_RGB32F_ARB                          , GL_RGB              , GL_FLOAT                                     }
+    , { GL_RGB16F_ARB                          , GL_RGB              , GL_FLOAT                                     }
+
 
+    , { GL_RGBA8                               , GL_RGBA             , GL_UNSIGNED_BYTE                             }
+    , { GL_RGB10_A2                            , GL_RGBA             , GL_UNSIGNED_INT_10_10_10_2                   }
+    , { GL_RGB10_A2                            , GL_RGBA             , GL_UNSIGNED_INT_2_10_10_10_REV               }
+    , { GL_RGBA12                              , GL_RGBA             , GL_UNSIGNED_SHORT                            }
+    , { GL_RGBA4                               , GL_RGBA             , GL_UNSIGNED_BYTE                             }
+    , { GL_RGBA4                               , GL_RGBA             , GL_UNSIGNED_SHORT_4_4_4_4                    }
+    , { GL_RGBA4                               , GL_RGBA             , GL_UNSIGNED_SHORT_4_4_4_4_REV                }
     , { GL_RGB5_A1                             , GL_RGBA             , GL_UNSIGNED_BYTE                             }
     , { GL_RGB5_A1                             , GL_RGBA             , GL_UNSIGNED_SHORT_5_5_5_1                    }
     , { GL_RGB5_A1                             , GL_RGBA             , GL_UNSIGNED_SHORT_1_5_5_5_REV                }
     , { GL_RGB5_A1                             , GL_RGBA             , GL_UNSIGNED_INT_10_10_10_2                   }
     , { GL_RGB5_A1                             , GL_RGBA             , GL_UNSIGNED_INT_2_10_10_10_REV               }
-    , { GL_RGBA4                               , GL_RGBA             , GL_UNSIGNED_BYTE                             }
-    , { GL_RGBA4                               , GL_RGBA             , GL_UNSIGNED_SHORT_4_4_4_4                    }
-    , { GL_RGBA4                               , GL_RGBA             , GL_UNSIGNED_SHORT_4_4_4_4_REV                }
-    , { GL_RGBA8                               , GL_RGBA             , GL_UNSIGNED_BYTE                             }
-    , { GL_RGB10_A2                            , GL_RGBA             , GL_UNSIGNED_INT_10_10_10_2                   }
-    , { GL_RGB10_A2                            , GL_RGBA             , GL_UNSIGNED_INT_2_10_10_10_REV               }
-    , { GL_RGBA12                              , GL_RGBA             , GL_UNSIGNED_SHORT                            }
  // , { GL_RGBA16F                             , GL_RGBA             , GL_HALF_FLOAT                                }
  // , { GL_RGBA16F                             , GL_RGBA             , GL_FLOAT                                     }
  // , { GL_RGBA32F                             , GL_RGBA             , GL_FLOAT                                     }
+
+    , { GL_SRGB8                               , GL_RGB              , GL_UNSIGNED_BYTE                             }
+    , { GL_SRGB8_ALPHA8                        , GL_RGBA             , GL_UNSIGNED_BYTE                             }
+
+    , { GL_R8_SNORM                            , GL_RED              , GL_BYTE                                      }
+    , { GL_R16_SNORM                           , GL_RED              , GL_SHORT                                     }
+    , { GL_RG8_SNORM                           , GL_RG               , GL_BYTE                                      }
+    , { GL_RG16_SNORM                          , GL_RG               , GL_SHORT                                     }
+    , { GL_RGB8_SNORM                          , GL_RGB              , GL_BYTE                                      }
+    , { GL_RGB16_SNORM                         , GL_RGB              , GL_SHORT                                     }
+    , { GL_RGBA8_SNORM                         , GL_RGBA             , GL_BYTE                                      }
 };
 
 InternalPixelRelations sizedDepthAndStencilInternalFormats[] = {
