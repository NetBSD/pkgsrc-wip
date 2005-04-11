# $NetBSD: Makefile,v 1.6 2005/04/11 21:13:39 tvierling Exp $
#

DISTNAME=	lbdb_0.29
PKGNAME=	lbdb-0.29
WRKSRC=		${WRKDIR}/lbdb-0.29
CATEGORIES=	mail
MASTER_SITES=	http://www.spinnaker.de/debian/

MAINTAINER=		drue@users.sf.net
HOMEPAGE=		http://www.spinnaker.de/debian/
COMMENT=		The little brother's database for the mutt mail reader

DEPENDS+=	p5-perl-ldap-[0-9]*:../../databases/p5-perl-ldap

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make

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
