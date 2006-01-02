# $NetBSD: Makefile,v 1.6 2006/01/02 09:06:21 rillig Exp $

DISTNAME=	pkg_fake-0.3
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pancake@phreaker.net
COMMENT=	pkgsrc tool to create and manage fake packages

NO_CONFIGURE=	yes
NO_CHECKSUM=	yes
NO_BUILD=	yes

DEPENDS+=	pkg_alternatives>=1.3:../../pkgtools/pkg_alternatives
DEPENDS+=	pkgfind>=20050804:../../pkgtools/pkgfind

do-extract:
	${MKDIR} ${WRKSRC:Q}
	${SED}	-e 's,@PREFIX@,${PREFIX},g'				\
		-e 's,@PKGDB@,${PKG_DBDIR},g'				\
		-e 's,@PKGSRC@,${PKGSRCDIR},g'				\
	< ${FILESDIR:Q}/pkg_fake					\
	> ${WRKSRC:Q}/pkg_fake
	${CP} ${FILESDIR:Q}/pkg_fake.1 ${WRKSRC:Q}/

do-install:
	${INSTALL_SCRIPT} ${WRKSRC:Q}/pkg_fake ${PREFIX:Q}/sbin/
	${INSTALL_MAN} ${WRKSRC:Q}/pkg_fake.1 ${PREFIX:Q}/man/man1/

.include "../../mk/bsd.pkg.mk"
