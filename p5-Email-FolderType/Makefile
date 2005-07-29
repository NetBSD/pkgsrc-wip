# $NetBSD: Makefile,v 1.1.1.1 2005/07/29 02:13:57 jgoamakf Exp $

DISTNAME=		Email-FolderType-0.8
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5eft
CATEGORIES=		mail perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Email/}

MAINTAINER=		hiramatu@boreas.dti.ne.jp
HOMEPAGE=		http://search.cpan.org/dist/Email-FolderType/
COMMENT=		Determine the type of a mail folder

DEPENDS+=		p5-Module-Pluggable>=2.8:../../devel/p5-Module-Pluggable

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Email/FolderType/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
