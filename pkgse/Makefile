# $NetBSD: Makefile,v 1.1.1.1 2004/04/29 13:26:45 imilh Exp $
#

DISTNAME=		pkgse-0.1
CATEGORIES=		pkgtools
MASTER_SITES=		http://imil.net/stuff/
EXTRACT_SUFX=		.tgz

MAINTAINER=		imil@gcu.info
HOMEPAGE=		http://imil.net/
COMMENT=		Fetch informations about a NetBSD package on pkgsrc.netbsd.se

DEPENDS+=		perl>=5.6.1nb1:../../lang/perl5
DEPENDS+=		p5-libwww>=5.76:../../www/p5-libwww

NO_CONFIGURE=		yes
NO_BUILD=		yes

do-install:
			cd ${WRKSRC} && 				\
			${INSTALL_SCRIPT} pkgse ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
