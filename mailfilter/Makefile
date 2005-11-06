# $NetBSD: Makefile,v 1.5 2005/11/06 11:25:57 leonardschmidt Exp $
#

DISTNAME=	mailfilter-0.7.1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mailfilter/}

MAINTAINER=	virtus@wanadoo.nl
HOMEPAGE=	http://mailfilter.sourceforge.net/
COMMENT=	Filter mail on a POP3 server

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake bison
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes

post-extract:
	@${RM} -f ${WRKSRC}/src/getopt.h

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libgetopt/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
