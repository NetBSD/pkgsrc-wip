# $NetBSD: Makefile,v 1.13 2003/10/22 18:23:18 jeremy-c-reed Exp $

DISTNAME=	${DISTFILES}
PKGNAME=	XFree86-libs-${XF_VER}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XFREE}
DISTFILES=	X430src-1.tgz X430src-2.tgz \
		X430src-3.tgz X430src-4.tgz

MAINTAINER=	xfree86@blef.org
HOMEPAGE=	http://www.xfree86.org/
COMMENT=	XFree86 Libraries

DEPENDS=	imake>=4.3.0:../../wip/imake

USE_BUILDLINK2=		YES

XBUILD_DIRS=		lib nls programs/Xserver/include \
			programs/Xserver/hw/xfree86/parser
XINCLUDE_DIRS=		programs/proxymngr
XINSTALL_DIRS=		include lib nls programs/Xserver/include \
			programs/Xserver/hw/xfree86/parser
XINSTALL_MAN_DIRS=	${XINSTALL_DIRS}

.include "../../mk/bsd.prefs.mk"

post-patch:
	${SED} -e 's,@MAKESTRS@,${X11BASE}/bin/makestrs,g' \
		${WRKSRC}/config/cf/Library.tmpl \
		> ${WRKSRC}/config/cf/Library.tmpl.tmp && \
		${MV} ${WRKSRC}/config/cf/Library.tmpl.tmp \
		${WRKSRC}/config/cf/Library.tmpl

.include "../../wip/XFree86/Makefile.common"
.include "../../fonts/fontconfig/buildlink2.mk"
.include "../../graphics/freetype2/buildlink2.mk"
.include "../../textproc/expat/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
