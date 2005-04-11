# $NetBSD: Makefile,v 1.5 2005/04/11 21:09:37 tvierling Exp $
#

DISTNAME=		Radiator-3.6
CATEGORIES=		net wip
MASTER_SITES=		# Need to get it yourself.
EXTRACT_SUFX=		.tgz

MAINTAINER=		cjep@NetBSD.org
HOMEPAGE=		http://www.open.com.au/radiator/
COMMENT=		RADIUS server implemented in Perl

DEPENDS+=		p5-Digest-MD5>=2.12:../../security/p5-Digest-MD5

RESTRICTED=		"Commercial software"
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}

INTERACTIVE_STAGE=	fetch

_FETCH_MESSAGE= \
	${ECHO} '==============================================';	\
	${ECHO} 'You need to purchase the source code for this '; 	\
	${ECHO} 'software from Open System Consultants Pty Ltd.';	\
	${ECHO} '=============================================='

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Radius/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
