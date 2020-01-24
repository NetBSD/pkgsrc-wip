# $NetBSD: Makefile,v 1.2 2012/10/07 14:53:43 asau Exp $
#

DISTNAME=	recutils-1.7
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GNU:=recutils/}

MAINTAINER=	esg@sdf.org
HOMEPAGE=	http://www.gnu.org/software/recutils/
COMMENT=	Tools and libraries to access plain text databases
LICENSE=	gnu-gpl-v3

#USE_TOOLS+=		lex yacc
GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
INFO_FILES=		yes

.include "../../security/libgcrypt/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
