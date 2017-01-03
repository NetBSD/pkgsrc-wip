# $NetBSD$

DISTNAME=	ranger-1.7.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils
MASTER_SITES=	http://ranger.nongnu.org/

MAINTAINER=	nahra@unseen.is
HOMEPAGE=	http://ranger.github.io/
COMMENT=	VIM-inspired filemanager for the console
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-curses-[0-9]*:../../devel/py-curses

BUILD_TARGET=	compile

CHECK_PORTABILITY_SKIP+=	examples/rifle_sxiv.sh

SUBST_CLASSES+=			install
SUBST_STAGE.install=		pre-install
SUBST_MESSAGE.install=		Fixing installation path
SUBST_FILES.install=		${WRKSRC}/setup.py
SUBST_SED.install=		-e 's,share/man,man,g'

SUBST_CLASSES+=			fix-gfmt
SUBST_STAGE.fix-gfmt=		post-patch
SUBST_MESSAGE.fix-gfmt=		Fixing fmt's binary name
SUBST_FILES.fix-gfmt=		${WRKSRC}/doc/config/scope.sh
SUBST_SED.fix-gfmt=		-e 's,fmt,gfmt,g'

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fixing absolute paths
SUBST_FILES.fix-paths=		${WRKSRC}/doc/ranger.1
SUBST_SED.fix-paths=		-e 's,/usr/share,${PREFIX}/share,g'
SUBST_SED.fix-paths+=		-e 's,/usr/lib,${PREFIX}/libexec,g'

REPLACE_PYTHON+=	*/*.py	*/*/*.py	*/*/*.py

USE_LANGUAGES=	# none

PKG_OPTIONS.libcaca+=	imlib2

.include	"options.mk"
.include	"../../lang/python/distutils.mk"
.include	"../../lang/python/application.mk"
.include	"../../mk/bsd.pkg.mk"
