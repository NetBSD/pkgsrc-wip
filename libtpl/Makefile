# $NetBSD$
#
GITHUB_PROJECT=	tpl
DISTNAME=	v1.6.1
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	wip
MASTER_SITES=	${MASTER_SITE_GITHUB:=troydhanson/}
EXTRACT_SUFX=	.zip
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	angelmadames@gmail.com
HOMEPAGE=	https://github.com/troydhanson/tpl/
COMMENT=	Store and reload your C data
LICENSE=	BSD

GNU_CONFIGURE= 	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	automake autoconf aclocal
USE_LANGUAGES=	c c++
WRKSRC=			${WRKDIR}/tpl-1.6.1
CONFIGURE_ARGS+=	${PREFIX}

pre-configure:
	set -x; cd ${WRKSRC}; libtoolize --copy --force; aclocal -I config; autoheader; automake --foreign --add-missing --copy; autoconf
post-install:
	${LIBTOOL} --finish ${PREFIX}/lib

.include "../../mk/bsd.pkg.mk"
