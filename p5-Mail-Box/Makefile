# $NetBSD: Makefile,v 1.3 2005/04/11 21:14:40 tvierling Exp $

DISTNAME=	Mail-Box-2.054
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Mail/}

MAINTAINER=	adrianp@stindustries.net
HOMEPAGE=	http://perl.overmeer.net/mailbox/
COMMENT=	Set of packages which implement methods to handle e-mail

DEPENDS+=	p5-TimeDate-[0-9]*:../../time/p5-TimeDate
DEPENDS+=	p5-File-Spec>=0.7:../../devel/p5-File-Spec
DEPENDS+=	p5-IO-stringy-[0-9]*:../../devel/p5-IO-stringy
DEPENDS+=	p5-Scalar-List-Utils>=1.13:../../devel/p5-Scalar-List-Utils
DEPENDS+=	p5-Object-Realize-Later>=0.14:../../devel/p5-Object-Realize-Later
DEPENDS+=	p5-MailTools-[0-9]*:../../mail/p5-MailTools
DEPENDS+=	p5-MIME-tools-[0-9]*:../../mail/p5-MIME-tools
DEPENDS+=	p5-MIME-Types>=1.004:../../mail/p5-MIME-Types
DEPENDS+=	p5-URI>=1.23:../../www/p5-URI
DEPENDS+=	p5-Test-Simple>=0.47:../../devel/p5-Test-Simple
DEPENDS+=	p5-User-Identity>=0.07:../../mail/p5-User-Identity
DEPENDS+=	p5-Mail-IMAPClient>=2.2:../../mail/p5-Mail-IMAPClient

PERL5_REQD?=	5.8.0

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Mail/Box/.packlist

# .include "../../lang/perl5/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
