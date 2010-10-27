# $NetBSD: Makefile,v 1.1.1.1 2010/10/27 11:05:43 ryo-on Exp $
#

DISTNAME=	korfont
CATEGORIES=	fonts
DISTFILES=	FontPack910_kor_i486-linux.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Asian Font Packs for Acrobat Reader 9 (Japanese)

DEPENDS+=	acroread9-font-share>=9.1:../../wip/acroread9-font-share

WRKSRC=		${WRKDIR}/KORKIT
TAR_FILE=	${WRKSRC}/LANGKOR.TAR

.include "../../wip/acroread9-font-share/Makefile.common"
