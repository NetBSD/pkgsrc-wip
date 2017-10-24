# $NetBSD$

DISTNAME=	elixir-0.2
PKGNAME=	${DISTNAME:S/elixir-/elixir-cross-ref-/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=free-electrons/}
GITHUB_PROJECT=	elixir
GITHUB_TAG=	v0.2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/free-electrons/elixir/
COMMENT=	Elixir Cross Referencer
LICENSE=	gnu-agpl-v3 # Patches are from AGPLv3 version

USE_LANGUAGES=			# none
USE_TOOLS+=			gsed:run perl:run pax
PYTHON_VERSIONS_ACCEPTED=	36 35
NO_BUILD=			yes

REPLACE_PYTHON=		data.py
REPLACE_PYTHON+=	lib.py
REPLACE_PYTHON+=	query.py
REPLACE_PYTHON+=	update.py
REPLACE_PYTHON+=	http/web.py

DEPENDS+=	${PYPKGPREFIX}-jinja2-[0-9]*:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-pygments-[0-9]*:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-bsddb3-[0-9]*:../../databases/py-bsddb3
DEPENDS+=	exctags-[0-9]*:../../devel/exctags
DEPENDS+=	coreutils-[0-9]*:../../sysutils/coreutils

SUBST_CLASSES+=			coreutils
SUBST_STAGE.coreutils=		pre-configure
SUBST_MESSAGE.coreutils=	Use GNU commands and exctags
SUBST_FILES.coreutils=		script.sh
SUBST_SED.coreutils=		-e 's,sort -V,gsort -V,g'
SUBST_SED.coreutils+=		-e 's,tac |,gtac |,g'
SUBST_SED.coreutils+=		-e 's,sed ,gsed ,g'
SUBST_SED.coreutils+=		-e 's,head ,ghead ,g'
SUBST_SED.coreutils+=		-e 's,ctags ,exctags ,g'

INSTALLATION_DIRS+=	share/doc/${PKGBASE}
INSTALLATION_DIRS+=	libexec/${PKGBASE}

do-install:
	${INSTALL_DATA} ${WRKSRC}/COPYING \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/README.md \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	cd ${WRKSRC} && ${FIND} . -type f  \! \( -name .gitignore -o \
		-name COPYING -o -name README.md -o -name '*.orig' \) -print | \
		pax -rw ${DESTDIR}${PREFIX}/libexec/${PKGBASE}

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
