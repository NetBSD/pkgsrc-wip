# $NetBSD: Makefile,v 1.9 2023/01/22 19:36:02 nikita Exp $

PKGNAME=	passphrase-git-1.5
CATEGORIES=	security
GIT_REPO=	https://git.sr.ht/~alva/passphrase

MAINTAINER=	nikita@NetBSD.org
HOMEPAGE=	https://git.sr.ht/~alva/passphrase
COMMENT=	Zero-dependency passphrase generator
LICENSE=	mit

WRKSRC=		${WRKDIR}/passphrase

CONFLICTS+=	passphrase-[0-9]*

# \todo: There is currently an issue building this as RELRO.
# RELRO_SUPPORTED=	no

ZIGBUILDARGS=		-Dpie=true
.if ${MKDEBUG:Uyes:M[yY][eE][sS]} && ${INSTALL_UNSTRIPPED:Uyes:tl} == yes
ZIGBUILDARGS+=		-Dstrip=true
.endif
ZIGBUILDMODE=		-Doptimize=ReleaseSafe

.include "../../lang/python/pyversion.mk"
CONFLICTS+=	${PYPKGPREFIX}-pyutil-[0-9]*


SUBST_CLASSES+=		mandir
SUBST_STAGE.mandir=	pre-build
SUBST_MESSAGE.mandir=	replacing mandir location
SUBST_FILES.mandir=	build.zig
SUBST_SED.mandir+=	-e 's,"share" ++ sep ++ "man","${PKGMANDIR}",g'

.include "../../wip/zig-git/application.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
