# $NetBSD: Makefile,v 1.2 2008/05/26 13:59:46 tnn2 Exp $
#

DISTNAME=	qpsmtpd-0.40
CATEGORIES=	mail
MASTER_SITES=	http://smtpd.develooper.com/files/

MAINTAINER=	ficovh@yahoo.com
HOMEPAGE=	http://smtpd.develooper.com/files/
COMMENT=	Flexible smtpd daemon written in Perl

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES= overwrite pkgviews

DEPENDS+=	p5-File-Temp>=0:../../devel/p5-File-Temp
DEPENDS+=	p5-MIME-Base64>=0:../../converters/p5-MIME-Base64
DEPENDS+=	p5-Net-DNS>=0.39:../../net/p5-Net-DNS
DEPENDS+=	p5-Time-HiRes>=0:../../time/p5-Time-HiRes

USE_TOOLS+=	pax

INSTALLATION_DIRS=	share/examples/qpsmtpd/

PERL5_PACKLIST=	auto/qpsmtpd/.packlist

post-install:
	cd ${WRKSRC}/plugins/ && pax -rw . ${DESTDIR}${PREFIX}/share/examples/qpsmtpd

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
