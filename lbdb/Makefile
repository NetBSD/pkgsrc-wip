# $NetBSD: Makefile,v 1.1.1.1 2003/06/27 11:16:04 drue Exp $
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

.include "../../mk/bsd.pkg.mk"
