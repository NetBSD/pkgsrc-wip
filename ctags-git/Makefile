# $NetBSD: Makefile,v 1.2 2015/08/10 18:59:28 jonthn Exp $

DISTNAME=	ctags-5.8
CATEGORIES=	devel
GIT_REPO=	git://github.com/universal-ctags/ctags

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctags.io/
COMMENT=	Maintained ctags implementation
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=		${PYPKGPREFIX}-docutils>=0.12:../../textproc/py-docutils
USE_TOOLS=		aclocal autoreconf autoconf automake autoheader
USE_TOOLS+=		bash gmake perl

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
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
