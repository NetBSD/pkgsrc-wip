# $NetBSD: Makefile,v 1.8 2009/04/29 22:06:15 thomasklausner Exp $

DISTNAME=	kdebase-${_KDE_VERSION}
CATEGORIES=	x11
COMMENT=	Base modules for the KDE 4 integrated X11 desktop

.include "../../wip/kde4/Makefile.kde4"

# BUILD_MAKE_FLAGS+= VERBOSE=1

# In 4.2.2, -j2 fails with:
# [ 44%] Building CXX object apps/konsole/src/CMakeFiles/konsolepart.dir/ColorSchemeEditor.o                                        
# .../kdebase-4.2.2/apps/konsole/src/ColorSchemeEditor.cpp:36:34: error: ui_ColorSchemeEditor.h: No such file or directory     
MAKE_JOBS_SAFE=	no

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../wip/kde4/kde4.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/qimageblitz/buildlink3.mk"
.include "../../wip/kdelibs4/buildlink3.mk"
.include "../../wip/kdebase-runtime4/buildlink3.mk"
.include "../../wip/kdebase-workspace4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
