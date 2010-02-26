# $NetBSD: Makefile,v 1.9 2010/02/26 10:30:14 thomasklausner Exp $
#

DISTNAME=		Radiator-3.6
CATEGORIES=		net
MASTER_SITES=		# Need to get it yourself.
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.open.com.au/radiator/
COMMENT=		RADIUS server implemented in Perl

DEPENDS+=		p5-Digest-MD5>=2.12:../../security/p5-Digest-MD5

RESTRICTED=		Commercial software
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}

INTERACTIVE_STAGE=	fetch

FETCH_MESSAGE+=		'You need to purchase the source code for this '
FETCH_MESSAGE+=		'software from Open System Consultants Pty Ltd.'

PERL5_PACKLIST=		auto/Radius/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
