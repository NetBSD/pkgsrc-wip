# $NetBSD: Makefile,v 1.2 2003/07/03 07:29:52 drue Exp $
#

DISTNAME=	lbdb_0.27
PKGNAME=	lbdb-0.27
WRKSRC=		${WRKDIR}/lbdb-0.27
CATEGORIES=		wip
MASTER_SITES=	http://www.spinnaker.de/debian/

MAINTAINER=		drue@users.sf.net
HOMEPAGE=		http://www.spinnaker.de/debian/
COMMENT=		adapter to various address db for use in mutt

DEPENDS+=	p5-perl-ldap-[0-9]*:../../databases/p5-perl-ldap

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_GMAKE=  yes

DOCDIR=	${PREFIX}/share/doc/${PKGBASE}

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	for f in COPYING README TODO; \
	do \
		${INSTALL_DATA} ${WRKSRC}/$${f} ${DOCDIR}; \
	done
	${INSTALL_DATA} ${WRKSRC}/debian/changelog ${DOCDIR}/ChangeLog
	${INSTALL_DATA} ${WRKSRC}/lbdb.sl ${PREFIX}/share/examples/lbdb/

.include "../../mk/bsd.pkg.mk"
