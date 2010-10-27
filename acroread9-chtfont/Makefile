# $NetBSD: Makefile,v 1.1.1.1 2010/10/27 12:12:14 ryo-on Exp $
#

DISTNAME=	chtfont
CATEGORIES=	fonts
DISTFILES=	FontPack910_cht_i486-linux.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Asian Font Packs for Acrobat Reader 9 (Chinese Traditional)

DEPENDS+=	acroread9-font-share>=9.1:../../wip/acroread9-font-share

WRKSRC=		${WRKDIR}/CHTKIT
TAR_FILE=	${WRKSRC}/LANGCHT.TAR

.include "../../wip/acroread9-font-share/Makefile.common"
