# $NetBSD: Makefile,v 1.2 2015/08/10 18:59:28 jonthn Exp $

DISTNAME=	ctags-5.8
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=universal-ctags/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctags.io/
COMMENT=	Maintained ctags implementation
LICENSE=	gnu-gpl-v2

GIT_REPOSITORIES=	ctags
GIT_REPO.ctags=		git://github.com/universal-ctags/ctags
GIT_MODULE.ctags=	ctags

WRKSRC=			${WRKDIR}/${GIT_MODULE.ctags}

BUILD_DEPENDS+=		${PYPKGPREFIX}-docutils>=0.12:../../textproc/py-docutils
USE_TOOLS=		aclocal autoreconf autoconf automake autoheader
USE_TOOLS+=		bash gmake perl

SUBST_CLASSES+=		bash
SUBST_MESSAGE.bash=	Fixing shellbang references to bash.
SUBST_STAGE.bash=	post-extract
SUBST_SED.bash=		-e 's,\#\!/bin/bash,\#\!${BASH},g'
SUBST_FILES.bash=	misc/optlib2c

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
