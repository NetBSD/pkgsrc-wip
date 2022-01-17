# $NetBSD$

DISTNAME=	ctags-5.9.20220116.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=universal-ctags/}
GITHUB_TAG=	p${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctags.io/
COMMENT=	Maintained ctags implementation
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=		${PYPKGPREFIX}-docutils>=0.12:../../textproc/py-docutils
USE_TOOLS=		aclocal autoreconf autoconf automake autoheader
USE_TOOLS+=		bash gmake perl pkg-config

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	RST2MAN=${PREFIX}/bin/rst2man-${PYVERSSUFFIX}
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
