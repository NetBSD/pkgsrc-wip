# $NetBSD: Makefile,v 1.1.1.1 2005/07/29 06:22:29 jgoamakf Exp $

DISTNAME=		Email-LocalDelivery-0.09
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5ems
CATEGORIES=		mail perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Email/}

MAINTAINER=		hiramatu@boreas.dti.ne.jp
HOMEPAGE=		http://search.cpan.org/dist/Email-LocalDelivery/
COMMENT=		Deliver a piece of email

DEPENDS+=		p5-Email-Simple>=1.92:../../mail/p5-Email-Simple
DEPENDS+=		p5-Email-FolderType>=0.07:../../wip/p5-Email-FolderType
DEPENDS+=		p5-File-Path-Expand>=1.01:../../wip/p5-File-Path-Expand

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Email/LocalDelivery/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
