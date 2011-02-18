# $NetBSD: Makefile,v 1.15 2011/02/18 14:05:26 pettai Exp $
#

DISTNAME=	sks-1.1.1
CATEGORIES=	security
MASTER_SITES=	http://sks-keyserver.googlecode.com/files/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://minskyprimus.net/sks/
COMMENT=	Self Replicating PGP Key Server
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

BUILDLINK_API_DEPENDS.ocaml+=	ocaml>=3.10.2
BUILDLINK_API_DEPENDS.db4+=	db4>=4.6.0

USE_TOOLS+=	gmake perl:run tar
BDB_ACCEPTED=	db4

MAKE_ENV+=	LIBDB=-ldb46 \
		BDBINCLUDE=-I${BUILDLINK_DIR}/include \
		BDBLIB=-L${BUILDLINK_DIR}/lib \
		PREFIX=${PREFIX:Q} \
		MANDIR=${PREFIX:Q}/man

INSTALLATION_DIRS=	${PKGMANDIR}/man8 bin

.include "../../lang/ocaml/buildlink3.mk"
.include "../../databases/db46/buildlink3.mk"

post-install:
	cd ${WRKSRC} && ${MAKE_PROGRAM} sks.8
	${INSTALL_PROGRAM} ${WRKSRC}/sks ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/sks_add_mail ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/sks.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8

.include "../../mk/bsd.pkg.mk"
