# $NetBSD: Makefile,v 1.8 2010/11/05 04:17:43 shattered Exp $

DISTNAME=	alphamail-1.0.44
PKGREVISION=	3
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=alphamail/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://alphamail.sourceforge.net/
COMMENT=	Highly scalable webmail with middleware component

BROKEN=		"Incompatible with boost 1.34+"

DEPENDS+=	p5-HTML-Mason>=1.30:../../www/p5-HTML-Mason
DEPENDS+=	p5-CGI>=3.20:../../www/p5-CGI
DEPENDS+=	p5-Apache2-AuthCookie>=3.10:../../www/p5-Apache2-AuthCookie
DEPENDS+=	p5-Apache-Session>=1.6:../../www/p5-Apache-Session
DEPENDS+=	p5-MIME-tools>=5.4:../../mail/p5-MIME-tools
DEPENDS+=	p5-MIME-Types>=1.16:../../mail/p5-MIME-Types
DEPENDS+=	p5-HTML-Parser>=3.45:../../www/p5-HTML-Parser
DEPENDS+=	p5-Log-Log4perl>=0.47:../../devel/p5-Log-Log4perl
DEPENDS+=	p5-Unicode-String>=2.0:../../converters/p5-Unicode-String
DEPENDS+=	p5-Unicode-Collate>=0.52:../../wip/p5-Unicode-Collate
DEPENDS+=	p5-Crypt-CBC>=2.14:../../security/p5-Crypt-CBC
DEPENDS+=	p5-Crypt-CAST5>=0.04:../../wip/p5-Crypt-CAST5
DEPENDS+=	p5-Text-Aspell>=0.04:../../textproc/p5-Text-Aspell
DEPENDS+=	p5-Time-HiRes>=1.59:../../time/p5-Time-HiRes
DEPENDS+=	p5-Digest-MD5>=2.0:../../security/p5-Digest-MD5
DEPENDS+=	p5-Date-Calc>=5.4:../../devel/p5-Date-Calc
DEPENDS+=	p5-Email-Date>=1.03:../../mail/p5-Email-Date
DEPENDS+=	p5-Email-AddressParser>=0.04:../../wip/p5-Email-AddressParser
DEPENDS+=	p5-Encode-IMAPUTF7>=1.00:../../wip/p5-Encode-IMAPUTF7

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	perl
# NetBSD 4.0 make segfaults at install time -- PR 37684?
USE_TOOLS+=	gmake
PTHREAD_AUTO_VARS=	yes

REPLACE_PERL=	util/alphamail_genconfig util/alphamail_stats \
		util/garbage_sweeper util/hang_detector

RCD_SCRIPTS=	imap_webcache

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../www/ap2-perl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
