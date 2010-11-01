# $NetBSD: Makefile,v 1.14 2010/11/01 00:08:22 thomasklausner Exp $
#

DISTNAME=	sks-1.0.9
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://savannah.nongnu.org/download/sks/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/sks/
COMMENT=	Self Replicating PGP Key Server

BUILDLINK_API_DEPENDS.ocaml+=	ocaml>=3.08.2
BUILDLINK_API_DEPENDS.db4+=	db4>=4.3.0

USE_TOOLS+=	gmake perl:run tar
BDB_ACCEPTED=	db4

MAKE_ENV+=	LIBDB=-ldb4 \
		BDBINCLUDE=-I${BUILDLINK_DIR}/include \
		BDBLIB=-L${BUILDLINK_DIR}/lib \
		PREFIX=${PREFIX:Q} \
		MANDIR=${PREFIX:Q}/man

.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bdb.buildlink3.mk"

pre-patch:
	cd ${WRKSRC} && ${TAR} xmfz numerix-0.19-3.tar.gz

post-install:
	cd ${WRKSRC} && ${MAKE_PROGRAM} sks.8
	${INSTALL_PROGRAM} ${WRKSRC}/sks ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/sks_add_mail ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/sks.8 ${PREFIX}/${PKGMANDIR}/man8

.include "../../mk/bsd.pkg.mk"
