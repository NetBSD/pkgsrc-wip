# $NetBSD: Makefile,v 1.1.1.1 2003/07/23 20:49:07 xtraeme Exp $
# $Id: Makefile,v 1.1.1.1 2003/07/23 20:49:07 xtraeme Exp $

DISTNAME=	${DISTFILES}
PKGNAME=	XFree86-clients-${XFREE86_VERSION}
CATEGORIES=	xfree86 x11
MASTER_SITES=	${MASTER_SITE_XFREE}
DISTFILES=	X430src-1.tgz X430src-2.tgz X430src-3.tgz X430src-4.tgz

MAINTAINER=	xfree86@xtraeme.unixbsd.org
HOMEPAGE=	http://www.xfree86.org/
COMMENT=	XFree86 client programs and related files

USE_BUILDLINK2=		yes
USE_PERL5=		yes

DISTINFO_FILE=		${.CURDIR}/../XFree86-libs/distinfo
PATCHDIR=		${.CURDIR}/../XFree86-libs/patches

XBUILD_DIRS=		lib/xtrans lib/lbxutil programs fonts/util
XINSTALL_DIRS=		programs fonts/util
XINSTALL_MAN_DIRS=	programs

REPLACE_PERL=		fonts/util/bdftruncate.pl fonts/util/ucs2any.pl

post-configure:
	@${MKDIR} ${WRKSRC}/exports/lib
	@for l in fntstubs Xss FS fontenc Xau Xxf86vm Xxf86dga xkbfile \
			Xxf86misc Xdmcp Xfontcache Xinerama Xfont; do \
		${LN} -sf ${PREFIX}/lib/lib$${l}.a ${WRKSRC}/exports/lib/ ; \
	done

.include "../../wip/XFree86/Makefile.common"
.include "../../graphics/png/buildlink2.mk"
.include "../../fonts/Xft2/buildlink2.mk"
.include "../../wip/XFree86-libs/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
