# $NetBSD$

DISTNAME=	ctags-2712201801
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=universal-ctags/}
GITHUB_TAG=	5728abe4112092437a517e94e30e139ccda63d5a

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctags.io/
COMMENT=	Maintained ctags implementation
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=		${PYPKGPREFIX}-docutils>=0.12:../../textproc/py-docutils
USE_TOOLS=		aclocal autoreconf autoconf automake autoheader
USE_TOOLS+=		bash gmake perl pkg-config

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	RST2MAN=${PREFIX}/bin/rst2man-${PYVERSSUFFIX}.py
CONFIGURE_ARGS+=	--enable-macro-patterns
CONFIGURE_ARGS+=	--enable-readlib
CONFIGURE_ARGS+=	--disable-readcmd
CONFIGURE_ARGS+=	--enable-custom-config=${PKG_SYSCONFDIR}/ctags.conf

CONFLICTS=	exctags-[0-9]*

pre-configure:
	cd ${WRKSRC} && ./autogen.sh


.include "options.mk"

.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
