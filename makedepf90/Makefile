# $NetBSD: Makefile,v 1.1.1.1 2006/02/12 00:59:00 emil_s Exp $
#

DISTNAME=		makedepf90-2.8.3
CATEGORIES=		devel
MASTER_SITES=		http://www.helsinki.fi/~eedelman/makedepf90/

MAINTAINER=		emil@math.su.se
HOMEPAGE=		http://www.helsinki.fi/~eedelman/makedepf90/
COMMENT=		Creates Makefile dependencies for Fortran code

USE_TOOLS+=		lex yacc autoconf 

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

pre-configure:
	cd ${WRKSRC} && autoconf

do-build:
	cd ${WRKSRC} && make


.include "../../mk/bsd.pkg.mk"
