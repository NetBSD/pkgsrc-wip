# $NetBSD: Makefile,v 1.6 2005/10/24 17:18:15 rillig Exp $
#

DISTNAME=	Radiator-all-3.6
CATEGORIES=	meta-pkgs net wip
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	cjep@NetBSD.org
HOMEPAGE=	# irrelevant
COMMENT=	Provides some useful modules for Radiator

DEPENDS+=	p5-Digest-MD4>=1.1:../../security/p5-Digest-MD4
DEPENDS+=	p5-perl-ldap>=0.22:../../databases/p5-perl-ldap
DEPENDS+=	p5-Net-SSLeay>=0.22:../../security/p5-Net-SSLeay
DEPENDS+=	p5-Digest-HMAC>=1.01:../../security/p5-Digest-HMAC
DEPENDS+=	p5-Digest-SHA1>=2.01:../../security/p5-Digest-SHA1
DEPENDS+=	p5-Tk>=800.002:../../x11/p5-Tk
DEPENDS+=	Radiator>=3.6:../../wip/Radiator

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
