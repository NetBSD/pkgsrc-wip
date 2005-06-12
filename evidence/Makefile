# $NetBSD: Makefile,v 1.5 2005/06/12 23:51:18 kristerw Exp $
#

DISTNAME=		evidence-0.9.8
CATEGORIES=		wip sysutils x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=evidence/}

MAINTAINER=		Peter.Bex@student.kun.nl
HOMEPAGE=		http://evidence.sourceforge.net/
COMMENT=		Enlightened file manager

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

# Optional modules.  This variable is similar to the MPLAYER_DRIVERS variable.
EVIDENCE_MODULES=							\
libvorbis	audio/libvorbis			libvorbis		\
id3		audio/id3lib			id3			\
curl		www/curl			curl			\
libxine		multimedia/xine-lib		thumbnailer-xine	\
libmpeg3	multimedia/libmpeg3		thumbnailer-mpeg3	\
avifile		multimedia/avifile		thumbnailer-avi		\
freetype	graphics/freetype2		plugin-ttf		\
glib		devel/glib			glib			\
ecore		wip/ecore			ecore			\
ecore		wip/ecore			ecore-ipc		\
kde		x11/kdelibs3			dcop			\
kde		x11/kdelibs3			backend-kio		\
gnome		x11/gnome-libs			canvas-gnomecanvas	\
gnome-vfs	sysutils/gnome-vfs		backend-gnomevfs2	\
evas		wip/evas			canvas-evas2

#
# By default, disable most modules.  This can be overridden by putting
# the variable in mk.conf.  glib isn't disabled because the main-loop from
# pkgsrc ecore is too old, so evidence can use glib's main-loop
#
EVIDENCE_DISABLE_MODULES?=libvorbis curl libxine libmpeg3 avifile kde	\
			  gnome gnome-vfs

# Modules for which we currently (apparently) do not have a package
EVIDENCE_NOPKG_MODULES= shared-mime dbus attrs acls plugin-extractor

.for mod pkg val in ${EVIDENCE_MODULES}
.  if empty(EVIDENCE_DISABLE_MODULES:M${mod})
CONFIGURE_ARGS+=        --enable-${val}
.    include "../../${pkg}/buildlink3.mk"
.  else
CONFIGURE_ARGS+=        --disable-${val}
.  endif
.endfor

# Explicitly disable this stuff so it won't be detected incorrectly
.for val in ${EVIDENCE_NOPKG_MODULES}
CONFIGURE_ARGS+=	--disable-${val}
.endfor

.include "../../devel/libltdl/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

#
# The following are really optional, but don't have configure switches.
# They are detected @ configure time, but not having them as dependency
# means users can simply remove a dependency and get into trouble. (?)
#
.include "../../sysutils/fam/buildlink3.mk"
.include "../../graphics/epeg/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
