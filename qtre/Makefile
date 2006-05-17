# $NetBSD: Makefile,v 1.1.1.1 2006/05/17 15:00:48 ivaniclixx Exp $
#

DISTNAME=		qtre-0.0.20060514.0
CATEGORIES=		editors
MASTER_SITES=		http://www.arrakis.es/~ninsesabe/qtre/
EXTRACT_SUFX=		.tgz

MAINTAINER=		ivaniclixx@gmail.com
HOMEPAGE=		http://www.arrakis.es/~ninsesabe/qtre/
COMMENT=		Quick Tool for Raw Editing

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

CONF_FILES=		${PREFIX}/etc/qtre.pl	# It crahes with "shift: can't shift that many"


.include "../../devel/ncurses/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
