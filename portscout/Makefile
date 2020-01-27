# $NetBSD: Makefile,v 1.1 2014/09/07 08:50:29 thomasklausner Exp $

DISTNAME=	portscout-0.8.1
CATEGORIES=	devel net
MASTER_SITES=	http://www.inerd.com/software/portscout/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.inerd.com/software/portscout/
COMMENT=	Check for new versions of software in the ports/pkgsrc tree
LICENSE=	2-clause-bsd

DEPENDS+=	p5-DBD-postgresql-[0-9]*:../../databases/p5-DBD-postgresql
DEPENDS+=	p5-DBI-[0-9]*:../../databases/p5-DBI
DEPENDS+=	p5-Proc-Queue-[0-9]*:../../devel/p5-Proc-Queue
DEPENDS+=	p5-Net-[0-9]*:../../net/p5-Net
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=	p5-MIME-Lite-[0-9]*:../../mail/p5-MIME-Lite
DEPENDS+=	p5-XML-XPath-[0-9]*:../../textproc/p5-XML-XPath

INSTALLATION_DIRS=	bin share/doc/portscout
INSTALLATION_DIRS+=	share/doc/portscout/sql
INSTALLATION_DIRS+=	share/doc/portscout/templates
INSTALLATION_DIRS+=	share/doc/portscout/web
INSTALLATION_DIRS+=	share/examples/portscout
INSTALLATION_DIRS+=	${PERL5_VENDORLIB}/Portscout

USE_LANGUAGES=	# none
USE_TOOLS+=	perl:run pax
REPLACE_PERL=	portscout.pl
# XXX: extract from perl package somehow
PERL5_API_VERS=	5.20.0

CONF_FILES+=	share/examples/portscout/portscout.conf ${PKG_SYSCONFDIR}/portscout.conf

do-build:

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/portscout.pl ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/Portscout.pm ${DESTDIR}${PERL5_VENDORLIB}
	${INSTALL_DATA} ${WRKSRC}/portscout.pod ${DESTDIR}${PERL5_VENDORLIB}
	cd ${WRKSRC}/Portscout/ && pax -pp -rw * ${DESTDIR}${PERL5_VENDORLIB}/Portscout/
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/portscout
	${INSTALL_DATA} ${WRKSRC}/docs/* ${DESTDIR}${PREFIX}/share/doc/portscout
	${INSTALL_DATA} ${WRKSRC}/sql/* ${DESTDIR}${PREFIX}/share/doc/portscout/sql
	${INSTALL_DATA} ${WRKSRC}/templates/* \
		${DESTDIR}${PREFIX}/share/doc/portscout/templates
	${INSTALL_DATA} ${WRKSRC}/web/* \
		${DESTDIR}${PREFIX}/share/doc/portscout/web
	${INSTALL_DATA} ${WRKSRC}/portscout.conf \
		${DESTDIR}${PREFIX}/share/examples/portscout

.include "../../mk/pgsql.buildlink3.mk"
.include "../../lang/perl5/dirs.mk"
.include "../../lang/perl5/vars.mk"
.include "../../mk/bsd.pkg.mk"
