# $NetBSD: Makefile,v 1.2 2015/09/19 13:43:00 outpaddling Exp $
#
# Don't bother committing this.  I'm adding new features almost every
# time I convert a port.

DISTNAME=	fbsd2pkg-0.6.0.10
CATEGORIES=	pkgtools
MASTER_SITES=	${MASTER_SITE_GITHUB:=outpaddling/}
GITHUB_TAG=	c2830e51d2d87bb1e2f7f0f5843907166d68a110

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/outpaddling/fbsd2pkg
COMMENT=	Convert a FreeBSD port framework to a pkgsrc package
LICENSE=	2-clause-bsd

USE_LANGUAGES=	# none

NO_BUILD=	yes

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	fbsd2pkg
SUBST_SED.prefix=	-e 's|fbsd2pkg.awk|${PREFIX}/libexec/fbsd2pkg/fbsd2pkg.awk|g'

DEPENDS+=	createbuildlink>=0:../../pkgtools/createbuildlink \
		pkglint>=0:../../pkgtools/pkglint

INSTALLATION_DIRS=	bin libexec/fbsd2pkg

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/fbsd2pkg ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/fbsd2pkg.awk \
		${DESTDIR}${PREFIX}/libexec/fbsd2pkg

.include "../../mk/bsd.pkg.mk"
