# $NetBSD: Makefile,v 1.4 2004/05/09 21:59:33 blef Exp $
#

DISTNAME=       avida-2.0b1
CATEGORIES=     misc
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=avida/}

MAINTAINER=     adam@monkeybyte.org
HOMEPAGE=       http://nemus.dllab.caltech.edu/avida/
COMMENT=        Avida is an auto-adaptive genetic system

USE_BUILDLINK3=         YES
HAS_CONFIGURE= YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS= --enable-viewer
USE_GNU_TOOLS+=	make

pre-configure:
	${ECHO} DESTDIR=${LOCALBASE}/share/avida >> ${WRKSRC}/doc/Makefile.in; \
	${ECHO} DESTDIR=${LOCALBASE}/share/avida >> ${WRKSRC}/doc/glossary/Makefile.in;

post-install:
	${MV} ${LOCALBASE}/work ${LOCALBASE}/avida-2.0b1
	${LN} -s ${LOCALBASE}/avida-2.0b1/primitive ${LOCALBASE}/bin/primitive
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
