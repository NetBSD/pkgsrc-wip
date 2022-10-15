# $NetBSD$

VERSION=	0.6.1
GITHUB_TAG=	v${VERSION}
DISTNAME=	docdiff-${VERSION}
PKGNAME=	${RUBY_PKGPREFIX}-docdiff-${VERSION}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=hisashim/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/hisashim/docdiff/
COMMENT=	Show char word line difference
LICENSE=	modified-bsd
WRKSRC=		${WRKDIR}/${DISTNAME}

USE_LANGUAGES=	# none

NO_BUILD=		yes
INSTALLATION_DIRS+=	${PREFIX}/share/docdiff ${PREFIX}/bin
REPLACE_RUBY=		bin/docdiff

SUBST_CLASSES+=		require
SUBST_STAGE.require=	pre-configure
SUBST_FILES.require+=	bin/docdiff
SUBST_SED.require=	-e 's,@@LIBRARY@@,${PREFIX}/share/docdiff,'

do-install:
	(cd   ${WRKSRC}/lib ; \
	${CP} -r  ./	      ${DESTDIR}${PREFIX}/share/docdiff ;\
	)
	(cd   ${WRKSRC}/bin ; \
	${INSTALL} docdiff    ${DESTDIR}${PREFIX}/bin ;\
	)

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
