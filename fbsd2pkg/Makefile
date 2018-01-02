# $NetBSD: Makefile,v 1.2 2015/09/19 13:43:00 outpaddling Exp $
#
# Don't bother committing this.  I'm adding new features almost every
# time I convert a port.

DISTNAME=	fbsd2pkg-0.5
CATEGORIES=	pkgtools
MASTER_SITES=	http://acadix.biz/Ports/distfiles/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	http://acadix.biz/Ports/distfiles/
COMMENT=	Convert a FreeBSD port framework to a pkgsrc package
LICENSE=	2-clause-bsd

USE_LANGUAGES=	# none

NO_BUILD=	yes

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	post-patch
SUBST_FILES.prefix=	${WRKSRC}/fbsd2pkg
SUBST_SED.prefix=	\
	's|fbsd2pkg.awk|${PREFIX}/libexec/fbsd2pkg/fbsd2pkg.awk|g'

DEPENDS+=	createbuildlink:../../pkgtools/createbuildlink \
		pkglint:../../pkgtools/pkglint

do-install:
	${MKDIR} ${DESTDIR}${PREFIX}/bin ${DESTDIR}${PREFIX}/libexec/fbsd2pkg
	${INSTALL_SCRIPT} ${WRKSRC}/fbsd2pkg ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/fbsd2pkg.awk \
		${DESTDIR}${PREFIX}/libexec/fbsd2pkg

.include "../../mk/bsd.pkg.mk"
