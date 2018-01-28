# $NetBSD: Makefile,v 1.11 2012/11/25 23:32:29 othyro Exp $

DISTNAME=	pkg_fake-0.3
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Tool for pkgsrc that creates and manages fake packages

NO_CONFIGURE=	yes
NO_BUILD=	yes

DEPENDS+=	pkg_alternatives>=1.3:../../pkgtools/pkg_alternatives
DEPENDS+=	pkgfind>=20050804:../../pkgtools/pkgfind

INSTALLATION_DIRS=	sbin ${PKGMANDIR}/man1

do-extract:
	${MKDIR} ${WRKSRC}
	${SED}	-e 's,@PREFIX@,${PREFIX},g'				\
		-e 's,@PKGDB@,${PKG_DBDIR},g'				\
		-e 's,@PKGSRC@,${PKGSRCDIR},g'				\
	< ${FILESDIR}/pkg_fake					\
	> ${WRKSRC}/pkg_fake
	${CP} ${FILESDIR}/pkg_fake.1 ${WRKSRC}/

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pkg_fake ${DESTDIR}${PREFIX}/sbin/
	${INSTALL_MAN} ${WRKSRC}/pkg_fake.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/

.include "../../mk/bsd.pkg.mk"
