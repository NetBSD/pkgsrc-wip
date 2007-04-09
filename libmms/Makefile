# $NetBSD: Makefile,v 1.2 2007/04/09 16:01:50 netcap Exp $
#

DISTNAME=	libmms-0.3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libmms/}

MAINTAINER=	jfranz@bsdprojects.net
HOMEPAGE=	http://libmms.sourceforge.net/
COMMENT=	Library for parsing mms:// and mmsh:// type network streams

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "FreeBSD"
SUBST_CLASSES=		includes
SUBST_STAGE.includes=	post-patch
SUBST_FILES.includes=	src/uri.c
SUBST_SED.includes=	-e "s|malloc.h|stdlib.h|"
SUBST_MESSAGE.includes=	Replacing malloc.h with stdlib.h for FreeBSD.
.endif

PKGCONFIG_OVERRIDE+=	pkgconfig/libmms.pc.in

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
