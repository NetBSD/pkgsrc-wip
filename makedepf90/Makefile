# $NetBSD: Makefile,v 1.2 2006/03/14 16:04:30 emil_s Exp $
#

DISTNAME=		makedepf90-2.8.4
CATEGORIES=		devel
MASTER_SITES=		http://www.helsinki.fi/~eedelman/makedepf90/

MAINTAINER=		emil@math.su.se
HOMEPAGE=		http://www.helsinki.fi/~eedelman/makedepf90/
COMMENT=		Creates Makefile dependencies for Fortran code

USE_TOOLS+=		lex yacc autoconf 

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

do-build:
	cd ${WRKSRC} && make


.include "../../mk/bsd.pkg.mk"
