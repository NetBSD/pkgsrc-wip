# $NetBSD: Makefile,v 1.5 2005/01/13 23:08:00 adrian_p Exp $
#

DISTNAME=	sks-1.0.9
CATEGORIES=	security
MASTER_SITES=	http://savannah.nongnu.org/download/sks/
EXTRACT_SUFX=	.tgz

MAINTAINER=	cube@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/sks/
COMMENT=	Self Replicating PGP Key Server

BUILDLINK_DEPENDS.ocaml+=	ocaml>=3.08.2
BUILDLINK_DEPENDS.db4+=		db4>=4.3.0

USE_BUILDLINK3=	YES
USE_GNU_TOOLS+=	make
BDB_ACCEPTED=	db4
USE_PERL5=	YES

MAKE_ENV+=	LIBDB=-ldb4 \
		BDBINCLUDE=-I${BUILDLINK_DIR}/include \
		BDBLIB=-L${BUILDLINK_DIR}/lib \
		PREFIX=${PREFIX} \
		MANDIR=${PREFIX}/man

.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bdb.buildlink3.mk"

pre-patch:
	@cd ${WRKSRC} && ${TAR} xmfz numerix-0.19-3.tar.gz

post-install:
	@cd ${WRKSRC} && ${MAKE_PROGRAM} sks.8
	${INSTALL_PROGRAM} ${WRKSRC}/sks ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/sks_add_mail ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/sks.8 ${PREFIX}/man/man8

.include "../../mk/bsd.pkg.mk"
