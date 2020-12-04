# $NetBSD: Makefile,v 1.1 2014/08/18 03:48:11 othyro Exp $
#

DISTNAME=	redmine-2.5.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://www.redmine.org/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.redmine.org/
COMMENT=	Flexible project management web application
LICENSE=	gnu-gpl-v2

DEPENDS+=	${RUBY_PKGPREFIX}-bundler>=1.0.2:../../misc/ruby-bundler
DEPENDS+=	${RUBY_PKGPREFIX}-rails>=3.2.17:../../www/ruby-rails32
DEPENDS+=	${RUBY_PKGPREFIX}-rake>=10.1.1:../../devel/ruby-rake
DEPENDS+=	${RUBY_PKGPREFIX}-jquery-rails>=2.0.2:../../www/ruby-jquery-rails
DEPENDS+=	${RUBY_PKGPREFIX}-coderay>=1.1.0:../../textproc/ruby-coderay
DEPENDS+=	${RUBY_PKGPREFIX}-fastercsv>=1.5.0:../../textproc/ruby-fastercsv
DEPENDS+=	${RUBY_PKGPREFIX}-builder>=3.0.0:../../textproc/ruby-builder
DEPENDS+=	${RUBY_PKGPREFIX}-mime-types-[0-9]*:../../mail/ruby-mime-types
DEPENDS+=	${RUBY_PKGPREFIX}-awesome_nested_set>=2.1.6:../../databases/ruby-awesome_nested_set

USE_LANGUAGES=	# none
#NO_CONFIGURE=	yes
#NO_BUILD=	yes

GEM_BUILD=	rake
REPLACE_RUBY+=	extra/svn/reposman.rb script/about script/rails
REPLACE_RUBY+=	public/dispatch.fcgi.example

INSTALLATION_DIRS+=	share/${PKGBASE}/app/controllers
INSTALLATION_DIRS+=	share/${PKGBASE}/app/helpers
INSTALLATION_DIRS+=	share/${PKGBASE}/app/models/repository
INSTALLATION_DIRS+=	share/${PKGBASE}/app/sweepers
INSTALLATION_DIRS+=	share/${PKGBASE}/app/views/account
INSTALLATION_DIRS+=	share/${PKGBASE}/app/views/activities
INSTALLATION_DIRS+=	share/${PKGBASE}/app/views/admin
INSTALLATION_DIRS+=	share/${PKGBASE}/app/views/attachments
INSTALLATION_DIRS+=	share/${PKGBASE}/app/views/auth_sources
INSTALLATION_DIRS+=	share/${PKGBASE}/app/views/auto_completes
INSTALLATION_DIRS+=	share/${PKGBASE}/app/views/boards
INSTALLATION_DIRS+=	share/${PKGBASE}/app/views/calendars
INSTALLATION_DIRS+=	share/${PKGBASE}/app/views/common
INSTALLATION_DIRS+=	share/${PKGBASE}/app/views/context_menus
INSTALLATION_DIRS+=	share/${PKGBASE}/app/views/custom_fields/formats
INSTALLATION_DIRS+=	share/${PKGBASE}/app/views/documents
INSTALLATION_DIRS+=	share/${PKGBASE}/app/views/enumerations
INSTALLATION_DIRS+=	share/${PKGBASE}/app/views/files
INSTALLATION_DIRS+=	share/${PKGBASE}/app/views/gantts
INSTALLATION_DIRS+=	share/${PKGBASE}/app/views/groups
INSTALLATION_DIRS+=	share/${PKGBASE}/app/views/issue_categories
INSTALLATION_DIRS+=	share/${PKGBASE}/app/views/issue_relations
INSTALLATION_DIRS+=	share/${PKGBASE}/app/views/issues
INSTALLATION_DIRS+=	share/${PKGBASE}/app/views/issue_statuses
INSTALLATION_DIRS+=	share/${PKGBASE}/app/views/journals
INSTALLATION_DIRS+=	share/${PKGBASE}/app/views/layouts
INSTALLATION_DIRS+=	share/${PKGBASE}/app/views/mailer
INSTALLATION_DIRS+=	share/${PKGBASE}/app/views/members
INSTALLATION_DIRS+=	share/${PKGBASE}/app/views/messages
INSTALLATION_DIRS+=	share/${PKGBASE}/app/views/my/blocks
INSTALLATION_DIRS+=	share/${PKGBASE}/app/views/news
INSTALLATION_DIRS+=	share/${PKGBASE}/app/views/previews
INSTALLATION_DIRS+=	share/${PKGBASE}/app/views/projects/settings
INSTALLATION_DIRS+=	share/${PKGBASE}/app/views/queries
INSTALLATION_DIRS+=	share/${PKGBASE}/app/views/reports
INSTALLATION_DIRS+=	share/${PKGBASE}/app/views/repositories
INSTALLATION_DIRS+=	share/${PKGBASE}/app/views/roles
INSTALLATION_DIRS+=	share/${PKGBASE}/app/views/search
INSTALLATION_DIRS+=	share/${PKGBASE}/app/views/settings
INSTALLATION_DIRS+=	share/${PKGBASE}/app/views/timelog
INSTALLATION_DIRS+=	share/${PKGBASE}/app/views/trackers
INSTALLATION_DIRS+=	share/${PKGBASE}/app/views/users
INSTALLATION_DIRS+=	share/${PKGBASE}/app/views/versions
INSTALLATION_DIRS+=	share/${PKGBASE}/app/views/watchers
INSTALLATION_DIRS+=	share/${PKGBASE}/app/views/welcome
INSTALLATION_DIRS+=	share/${PKGBASE}/app/views/wiki
INSTALLATION_DIRS+=	share/${PKGBASE}/app/views/wikis
INSTALLATION_DIRS+=	share/${PKGBASE}/app/views/workflows
INSTALLATION_DIRS+=	share/${PKGBASE}/config/environments
INSTALLATION_DIRS+=	share/${PKGBASE}/config/initializers
INSTALLATION_DIRS+=	share/${PKGBASE}/config/locales
INSTALLATION_DIRS+=	share/${PKGBASE}/db/migrate share/doc/${PKGBASE}
INSTALLATION_DIRS+=	share/${PKGBASE}/extra/mail_handler
INSTALLATION_DIRS+=	share/${PKGBASE}/extra/sample_plugin/app/controllers
INSTALLATION_DIRS+=	share/${PKGBASE}/extra/sample_plugin/app/models
INSTALLATION_DIRS+=	share/${PKGBASE}/extra/sample_plugin/app/views/example
INSTALLATION_DIRS+=	share/${PKGBASE}/extra/sample_plugin/app/views/my/blocks
INSTALLATION_DIRS+=	share/${PKGBASE}/extra/sample_plugin/app/views/settings
INSTALLATION_DIRS+=	share/${PKGBASE}/extra/sample_plugin/assets/images
INSTALLATION_DIRS+=	share/${PKGBASE}/extra/sample_plugin/assets/stylesheets
INSTALLATION_DIRS+=	share/${PKGBASE}/extra/sample_plugin/config/locales
INSTALLATION_DIRS+=	share/${PKGBASE}/extra/sample_plugin/db/migrate
INSTALLATION_DIRS+=	share/${PKGBASE}/extra/sample_plugin/test/integration
INSTALLATION_DIRS+=	share/${PKGBASE}/extra/svn share/${PKGBASE}/files
INSTALLATION_DIRS+=	share/${PKGBASE}/lib/generators/redmine_plugin_controller/templates
INSTALLATION_DIRS+=	share/${PKGBASE}/lib/generators/redmine_plugin_model/templates
INSTALLATION_DIRS+=	share/${PKGBASE}/lib/generators/redmine_plugin/templates
INSTALLATION_DIRS+=	share/${PKGBASE}/lib/plugins/acts_as_activity_provider/lib
INSTALLATION_DIRS+=	share/${PKGBASE}/lib/plugins/acts_as_attachable/lib
INSTALLATION_DIRS+=	share/${PKGBASE}/lib/plugins/acts_as_customizable/lib
INSTALLATION_DIRS+=	share/${PKGBASE}/lib/plugins/acts_as_event/lib
INSTALLATION_DIRS+=	share/${PKGBASE}/lib/plugins/acts_as_list/lib/active_record/acts
INSTALLATION_DIRS+=	share/${PKGBASE}/lib/plugins/acts_as_list/test
INSTALLATION_DIRS+=	share/${PKGBASE}/lib/plugins/acts_as_searchable/lib
INSTALLATION_DIRS+=	share/${PKGBASE}/lib/plugins/acts_as_tree/lib/active_record/acts
INSTALLATION_DIRS+=	share/${PKGBASE}/lib/plugins/acts_as_tree/test/fixtures
INSTALLATION_DIRS+=	share/${PKGBASE}/lib/plugins/acts_as_versioned/lib
INSTALLATION_DIRS+=	share/${PKGBASE}/lib/plugins/acts_as_versioned/test/fixtures/migrations
INSTALLATION_DIRS+=	share/${PKGBASE}/lib/plugins/acts_as_watchable/lib
INSTALLATION_DIRS+=	share/${PKGBASE}/lib/plugins/gravatar/lib
INSTALLATION_DIRS+=	share/${PKGBASE}/lib/plugins/gravatar/spec
INSTALLATION_DIRS+=	share/${PKGBASE}/lib/plugins/open_id_authentication/generators/open_id_authentication_tables/templates
INSTALLATION_DIRS+=	share/${PKGBASE}/lib/plugins/open_id_authentication/generators/upgrade_open_id_authentication_tables/templates
INSTALLATION_DIRS+=	share/${PKGBASE}/lib/plugins/open_id_authentication/lib/open_id_authentication
INSTALLATION_DIRS+=	share/${PKGBASE}/lib/plugins/open_id_authentication/lib/tasks
INSTALLATION_DIRS+=	share/${PKGBASE}/lib/plugins/open_id_authentication/test
INSTALLATION_DIRS+=	share/${PKGBASE}/lib/plugins/rfpdf/lib/config/lang
INSTALLATION_DIRS+=	share/${PKGBASE}/lib/plugins/rfpdf/lib/core
INSTALLATION_DIRS+=	share/${PKGBASE}/lib/plugins/rfpdf/lib/fonts/dejavu-ttf-2.15
INSTALLATION_DIRS+=	share/${PKGBASE}/lib/plugins/rfpdf/lib/fonts/freefont
INSTALLATION_DIRS+=	share/${PKGBASE}/lib/plugins/rfpdf/lib/fonts/old/makefont
INSTALLATION_DIRS+=	share/${PKGBASE}/lib/plugins/rfpdf/lib/fonts/ttf2ufm
INSTALLATION_DIRS+=	share/${PKGBASE}/lib/plugins/rfpdf/lib/fonts/ttf-bitstream-vera-1.10
INSTALLATION_DIRS+=	share/${PKGBASE}/lib/plugins/rfpdf/lib/fpdf
INSTALLATION_DIRS+=	share/${PKGBASE}/lib/plugins/rfpdf/lib/rfpdf/template_handler
INSTALLATION_DIRS+=	share/${PKGBASE}/lib/plugins/rfpdf/lib/rfpdf/template_handlers
INSTALLATION_DIRS+=	share/${PKGBASE}/lib/plugins/rfpdf/test
INSTALLATION_DIRS+=	share/${PKGBASE}/lib/redmine
INSTALLATION_DIRS+=	share/${PKGBASE}/lib/redmine/activity
INSTALLATION_DIRS+=	share/${PKGBASE}/lib/redmine/core_ext/date
INSTALLATION_DIRS+=	share/${PKGBASE}/lib/redmine/core_ext/string
INSTALLATION_DIRS+=	share/${PKGBASE}/lib/redmine/default_data
INSTALLATION_DIRS+=	share/${PKGBASE}/lib/redmine/export
INSTALLATION_DIRS+=	share/${PKGBASE}/lib/redmine/helpers
INSTALLATION_DIRS+=	share/${PKGBASE}/lib/redmine/scm/adapters/mercurial
INSTALLATION_DIRS+=	share/${PKGBASE}/lib/redmine/views/builders
INSTALLATION_DIRS+=	share/${PKGBASE}/lib/redmine/views/my_page
INSTALLATION_DIRS+=	share/${PKGBASE}/lib/redmine/wiki_formatting/markdown
INSTALLATION_DIRS+=	share/${PKGBASE}/lib/redmine/wiki_formatting/textile
INSTALLATION_DIRS+=	share/${PKGBASE}/lib/SVG/Graph
INSTALLATION_DIRS+=	share/${PKGBASE}/lib/tasks share/${PKGBASE}/lib/vendor
INSTALLATION_DIRS+=	share/${PKGBASE}/log share/${PKGBASE}/plugins
INSTALLATION_DIRS+=	share/${PKGBASE}/public/help/ar
INSTALLATION_DIRS+=	share/${PKGBASE}/public/help/az
INSTALLATION_DIRS+=	share/${PKGBASE}/public/help/bg
INSTALLATION_DIRS+=	share/${PKGBASE}/public/help/bs
INSTALLATION_DIRS+=	share/${PKGBASE}/public/help/ca
INSTALLATION_DIRS+=	share/${PKGBASE}/public/help/cs
INSTALLATION_DIRS+=	share/${PKGBASE}/public/help/da
INSTALLATION_DIRS+=	share/${PKGBASE}/public/help/de
INSTALLATION_DIRS+=	share/${PKGBASE}/public/help/el
INSTALLATION_DIRS+=	share/${PKGBASE}/public/help/en
INSTALLATION_DIRS+=	share/${PKGBASE}/public/help/en-gb
INSTALLATION_DIRS+=	share/${PKGBASE}/public/help/es
INSTALLATION_DIRS+=	share/${PKGBASE}/public/help/et
INSTALLATION_DIRS+=	share/${PKGBASE}/public/help/eu
INSTALLATION_DIRS+=	share/${PKGBASE}/public/help/fa
INSTALLATION_DIRS+=	share/${PKGBASE}/public/help/fi
INSTALLATION_DIRS+=	share/${PKGBASE}/public/help/fr
INSTALLATION_DIRS+=	share/${PKGBASE}/public/help/gl
INSTALLATION_DIRS+=	share/${PKGBASE}/public/help/he
INSTALLATION_DIRS+=	share/${PKGBASE}/public/help/hr
INSTALLATION_DIRS+=	share/${PKGBASE}/public/help/hu
INSTALLATION_DIRS+=	share/${PKGBASE}/public/help/id
INSTALLATION_DIRS+=	share/${PKGBASE}/public/help/it
INSTALLATION_DIRS+=	share/${PKGBASE}/public/help/ja
INSTALLATION_DIRS+=	share/${PKGBASE}/public/help/ko
INSTALLATION_DIRS+=	share/${PKGBASE}/public/help/lt
INSTALLATION_DIRS+=	share/${PKGBASE}/public/help/lv
INSTALLATION_DIRS+=	share/${PKGBASE}/public/help/mk
INSTALLATION_DIRS+=	share/${PKGBASE}/public/help/mn
INSTALLATION_DIRS+=	share/${PKGBASE}/public/help/nl
INSTALLATION_DIRS+=	share/${PKGBASE}/public/help/no
INSTALLATION_DIRS+=	share/${PKGBASE}/public/help/pl
INSTALLATION_DIRS+=	share/${PKGBASE}/public/help/pt
INSTALLATION_DIRS+=	share/${PKGBASE}/public/help/pt-br
INSTALLATION_DIRS+=	share/${PKGBASE}/public/help/ro
INSTALLATION_DIRS+=	share/${PKGBASE}/public/help/ru
INSTALLATION_DIRS+=	share/${PKGBASE}/public/help/sk
INSTALLATION_DIRS+=	share/${PKGBASE}/public/help/sl
INSTALLATION_DIRS+=	share/${PKGBASE}/public/help/sq
INSTALLATION_DIRS+=	share/${PKGBASE}/public/help/sr
INSTALLATION_DIRS+=	share/${PKGBASE}/public/help/sr-yu
INSTALLATION_DIRS+=	share/${PKGBASE}/public/help/sv
INSTALLATION_DIRS+=	share/${PKGBASE}/public/help/th
INSTALLATION_DIRS+=	share/${PKGBASE}/public/help/tr
INSTALLATION_DIRS+=	share/${PKGBASE}/public/help/uk
INSTALLATION_DIRS+=	share/${PKGBASE}/public/help/vi
INSTALLATION_DIRS+=	share/${PKGBASE}/public/help/zh
INSTALLATION_DIRS+=	share/${PKGBASE}/public/help/zh-tw
INSTALLATION_DIRS+=	share/${PKGBASE}/public/images/files
INSTALLATION_DIRS+=	share/${PKGBASE}/public/images/jstoolbar
INSTALLATION_DIRS+=	share/${PKGBASE}/public/javascripts/i18n
INSTALLATION_DIRS+=	share/${PKGBASE}/public/javascripts/jstoolbar/lang
INSTALLATION_DIRS+=	share/${PKGBASE}/public/stylesheets/jquery/images
INSTALLATION_DIRS+=	share/${PKGBASE}/public/themes/alternate/stylesheets
INSTALLATION_DIRS+=	share/${PKGBASE}/public/themes/classic/images
INSTALLATION_DIRS+=	share/${PKGBASE}/public/themes/classic/stylesheets
INSTALLATION_DIRS+=	share/${PKGBASE}/script share/${PKGBASE}/test
INSTALLATION_DIRS+=	share/${PKGBASE}/test/extra/redmine_pm
INSTALLATION_DIRS+=	share/${PKGBASE}/test/fixtures/configuration
INSTALLATION_DIRS+=	share/${PKGBASE}/test/fixtures/diffs
INSTALLATION_DIRS+=	share/${PKGBASE}/test/fixtures/encoding
INSTALLATION_DIRS+=	share/${PKGBASE}/test/fixtures/files/2006/07
INSTALLATION_DIRS+=	share/${PKGBASE}/test/fixtures/files/2010/11
INSTALLATION_DIRS+=	share/${PKGBASE}/test/fixtures/files/2010/12
INSTALLATION_DIRS+=	share/${PKGBASE}/test/fixtures/ldap
INSTALLATION_DIRS+=	share/${PKGBASE}/test/fixtures/mailer
INSTALLATION_DIRS+=	share/${PKGBASE}/test/fixtures/mail_handler
INSTALLATION_DIRS+=	share/${PKGBASE}/test/fixtures/plugins/foo_plugin
INSTALLATION_DIRS+=	share/${PKGBASE}/test/fixtures/repositories
INSTALLATION_DIRS+=	share/${PKGBASE}/test/functional
INSTALLATION_DIRS+=	share/${PKGBASE}/test/integration/api_test
INSTALLATION_DIRS+=	share/${PKGBASE}/test/integration/lib/redmine
INSTALLATION_DIRS+=	share/${PKGBASE}/test/integration/routing
INSTALLATION_DIRS+=	share/${PKGBASE}/test/mocks/development
INSTALLATION_DIRS+=	share/${PKGBASE}/test/mocks/test
INSTALLATION_DIRS+=	share/${PKGBASE}/test/ui
INSTALLATION_DIRS+=	share/${PKGBASE}/test/unit/helpers
INSTALLATION_DIRS+=	share/${PKGBASE}/test/unit/initializers
INSTALLATION_DIRS+=	share/${PKGBASE}/test/unit/lib/redmine/export
INSTALLATION_DIRS+=	share/${PKGBASE}/test/unit/lib/redmine/field_format
INSTALLATION_DIRS+=	share/${PKGBASE}/test/unit/lib/redmine/helpers
INSTALLATION_DIRS+=	share/${PKGBASE}/test/unit/lib/redmine/menu_manager
INSTALLATION_DIRS+=	share/${PKGBASE}/test/unit/lib/redmine/scm/adapters
INSTALLATION_DIRS+=	share/${PKGBASE}/test/unit/lib/redmine/utils
INSTALLATION_DIRS+=	share/${PKGBASE}/test/unit/lib/redmine/views
INSTALLATION_DIRS+=	share/${PKGBASE}/test/unit/lib/redmine/views/builders
INSTALLATION_DIRS+=	share/${PKGBASE}/test/unit/lib/redmine/wiki_formatting
INSTALLATION_DIRS+=	share/${PKGBASE}/tmp/cache share/${PKGBASE}/tmp/pdf
INSTALLATION_DIRS+=	share/${PKGBASE}/tmp/sessions
INSTALLATION_DIRS+=	share/${PKGBASE}/tmp/sockets share/${PKGBASE}/tmp/test
INSTALLATION_DIRS+=	share/${PKGBASE}/tmp/thumbnails share/${PKGBASE}/vendor

.include "options.mk"

#do-install:
#	set -e; cd ${WRKSRC};
#	for i in `find . -path ./doc -prune -o -type f ! -perm 775 -print`; do
#		${INSTALL_DATA} $$i ${DESTDIR}${PREFIX}/share/${PKGBASE}/$$i;
#	done;
#	for i in `find . -type f -executable -not -name ttf2ufm\\* -print`; do
#		${INSTALL_SCRIPT} $$i
#		${DESTDIR}${PREFIX}/share/${PKGBASE}/$$i;
#	done;
#	${INSTALL_DATA} doc/* ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
