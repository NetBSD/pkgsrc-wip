# $NetBSD$

DISTNAME=	astguiclient_2.13rc1
PKGNAME=	vicidial-2.13rc1
CATEGORIES=	net devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=astguiclient/}
EXTRACT_SUFX=	.zip
LICENSE=	gnu-agpl-v3

MAINTAINER=	angelmadames@gmail.com
HOMEPAGE=	https://sourceforge.net/projects/astguiclient/
COMMENT=	Asterisk GUI client, VICIdial

NO_BUILD=	yes
USE_TOOLS+=	perl
REPLACE_PERL+=	install.pl

DEPENDS+=	p5-DBI>=1.6:../../databases/p5-DBI
DEPENDS+=	p5-DBD-mysql>=1.6:../../databases/p5-DBD-mysql
DEPENDS+=	p5-Digest-MD5>=2.5:../../security/p5-Digest-MD5
DEPENDS+=	p5-Digest-SHA1>=2.1:../../security/p5-Digest-SHA1
DEPENDS+=	p5-Pod-Usage>=1.6:../../devel/p5-Pod-Usage
DEPENDS+=	p5-Getopt-Long>=2.5:../../devel/p5-Getopt-Long
DEPENDS+=	p5-Net-Telnet>=3.0:../../net/p5-Net-Telnet
DEPENDS+=	p5-Time-HiRes>=1.9:../../time/p5-Time-HiRes
DEPENDS+=	p5-Net-Server>=2.0:../../net/p5-Net-Server
DEPENDS+=	p5-Mail-Sendmail>=0.7:../../mail/p5-Mail-Sendmail
DEPENDS+=	p5-Unicode-Map>=0.1:../../converters/p5-Unicode-Map
DEPENDS+=	p5-Jcode>=1.6:../../converters/p5-Jcode
	# Needed for Super List Loader:
DEPENDS+=	p5-Spreadsheet-WriteExcel>=2.4:../../math/p5-Spreadsheet-WriteExcel
DEPENDS+=	p5-Spreadsheet-ReadSXC>=0.2:../../math/p5-Spreadsheet-ReadSXC
DEPENDS+=	p5-Spreadsheet-ParseExcel>=0.6:../../math/p5-Spreadsheet-ParseExcel
DEPENDS+=	p5-Spreadsheet-Read>=0.7:../../math/p5-Spreadsheet-Read
DEPENDS+=	p5-Spreadsheet-XLSX>=0.1:../../math/p5-Spreadsheet-XLSX
DEPENDS+=	p5-OLE-Storage_Lite>=0.1:../../devel/p5-OLE-Storage_Lite
DEPENDS+=	p5-Proc-ProcessTable>=0.5:../../devel/p5-Proc-ProcessTable
DEPENDS+=	p5-IO-stringy>=2.1:../../devel/p5-IO-stringy
DEPENDS+=	p5-Archive-Zip>=1.5:../../archivers/p5-Archive-Zip
DEPENDS+=	p5-Compress-Raw-Zlib>=2.0:../../devel/p5-Compress-Raw-Zlib
DEPENDS+=	p5-Test-Simple>=1.3:../../devel/p5-Test-Simple
DEPENDS+=	p5-Text-CSV>=1.6:../../textproc/p5-Text-CSV
DEPENDS+=	p5-Test-NoWarnings>=1.0:../../devel/p5-Test-NoWarnings
DEPENDS+=	p5-File-Temp>=0.2:../../devel/p5-File-Temp
DEPENDS+=	p5-libwww>=6.2:../../www/p5-libwww
DEPENDS+=	p5-HTML-Parser>=3.7:../../www/p5-HTML-Parser
DEPENDS+=	p5-HTML-Strip>=1.6:../../www/p5-HTML-Strip
DEPENDS+=	p5-HTML-Format>=2.12:../../www/p5-HTML-Format
DEPENDS+=	p5-HTML-Tree>=5.0:../../www/p5-HTML-Tree
DEPENDS+=	p5-Switch>=2.1:../../lang/p5-Switch
DEPENDS+=	p5-Time-Local>=1.25:../../time/p5-Time-Local
DEPENDS+=	p5-Mail-Message>=3.0:../../wip/p5-Mail-Message
DEPENDS+=	p5-Mail-IMAPClient>=3.3:../../mail/p5-Mail-IMAPClient
DEPENDS+=	p5-Mail-POP3Client>=2.1:../../mail/p5-Mail-POP3Client
DEPENDS+=	p5-IO-Socket-SSL>=2.0:../../security/p5-IO-Socket-SSL
DEPENDS+=	p5-Crypt-Eksblowfish>=0.0:../../security/p5-Crypt-Eksblowfish
DEPENDS+=	p5-IO-tty>=1.1:../../devel/p5-IO-Tty
DEPENDS+=	p5-MIME-Base64>=3.1:../../converters/p5-MIME-Base64
DEPENDS+=	p5-Net-SFTP-Foreign>=1.8:../../wip/p5-Net-SFTP-Foreign

WRKSRC=		${WRKDIR}
BUILD_DEFS+=	VARBASE

do-install:
	cd ${WRKSRC}; \
	${BUILDLINK_PREFIX.perl}/bin/perl install.pl \
	--no-prompt \
	--debug \
	--conffile=${PREFIX}/etc/astguiclient.conf \
	--home=${PREFIX}/share/vicidial \
	--logs=${VARBASE}/log/vicidial \
	--agi=${PREFIX}/libexec/agi-bin \
	--web=${PREFIX}/share/vicidial/www \
	--sounds=${VARBASE}/lib/asterisk/sounds \
	--monitor=${VARBASE}/spool/asterisk/monitorDONE;

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
