# $NetBSD: Makefile,v 1.1 2007/03/30 11:52:45 cheusov Exp $
#

DISTNAME=		xmms-cdread-0.14a
CATEGORIES=		audio
MASTER_SITES=		ftp://mud.stack.nl/pub/OuterSpace/willem/

MAINTAINER=		cheusov@tut.by
HOMEPAGE=		ftp://mud.stack.nl/pub/OuterSpace/willem/
COMMENT=		XMMS input plugin that reads audio data from CDs

GNU_CONFIGURE=		yes

DOC_FILES=		AUTHORS ChangeLog COPYING NEWS README
PKGDOCDIR=		${PREFIX}/share/doc/${PKGBASE}

INSTALLATION_DIRS=	${PKGDOCDIR}

post-install:
.for i in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${PKGDOCDIR}
.endfor

.include "../../audio/xmms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
