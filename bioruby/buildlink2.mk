# $NetBSD: buildlink2.mk,v 1.1.1.1 2005/02/25 20:18:24 daprice Exp $
#
# This Makefile fragment is included by packages that use bioruby.
#
# This file was created automatically using createbuildlink 2.6.
#

.if !defined(BIORUBY_BUILDLINK2_MK)
BIORUBY_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			bioruby
BUILDLINK_DEPENDS.bioruby?=		bioruby>=0.4.0
BUILDLINK_PKGSRCDIR.bioruby?=		../../biology/bioruby

EVAL_PREFIX+=	BUILDLINK_PREFIX.bioruby=bioruby
BUILDLINK_PREFIX.bioruby_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.bioruby+=	lib/ruby/site_ruby/1.6/bio.rb
BUILDLINK_FILES.bioruby+=	lib/ruby/site_ruby/1.6/bio/appl/blast.rb
BUILDLINK_FILES.bioruby+=	lib/ruby/site_ruby/1.6/bio/appl/blast/format8.rb
BUILDLINK_FILES.bioruby+=	lib/ruby/site_ruby/1.6/bio/appl/blast/rexml.rb
BUILDLINK_FILES.bioruby+=	lib/ruby/site_ruby/1.6/bio/appl/blast/xmlparser.rb
BUILDLINK_FILES.bioruby+=	lib/ruby/site_ruby/1.6/bio/appl/emboss.rb
BUILDLINK_FILES.bioruby+=	lib/ruby/site_ruby/1.6/bio/appl/fasta.rb
BUILDLINK_FILES.bioruby+=	lib/ruby/site_ruby/1.6/bio/appl/fasta/format10.rb
BUILDLINK_FILES.bioruby+=	lib/ruby/site_ruby/1.6/bio/appl/fasta/format6.rb
BUILDLINK_FILES.bioruby+=	lib/ruby/site_ruby/1.6/bio/appl/hmmer.rb
BUILDLINK_FILES.bioruby+=	lib/ruby/site_ruby/1.6/bio/appl/hmmer/report.rb
BUILDLINK_FILES.bioruby+=	lib/ruby/site_ruby/1.6/bio/data/aa.rb
BUILDLINK_FILES.bioruby+=	lib/ruby/site_ruby/1.6/bio/data/codontable.rb
BUILDLINK_FILES.bioruby+=	lib/ruby/site_ruby/1.6/bio/data/keggorg.rb
BUILDLINK_FILES.bioruby+=	lib/ruby/site_ruby/1.6/bio/data/na.rb
BUILDLINK_FILES.bioruby+=	lib/ruby/site_ruby/1.6/bio/db.rb
BUILDLINK_FILES.bioruby+=	lib/ruby/site_ruby/1.6/bio/db/aaindex.rb
BUILDLINK_FILES.bioruby+=	lib/ruby/site_ruby/1.6/bio/db/embl.rb
BUILDLINK_FILES.bioruby+=	lib/ruby/site_ruby/1.6/bio/db/embl/embl.rb
BUILDLINK_FILES.bioruby+=	lib/ruby/site_ruby/1.6/bio/db/embl/sptr.rb
BUILDLINK_FILES.bioruby+=	lib/ruby/site_ruby/1.6/bio/db/embl/swissprot.rb
BUILDLINK_FILES.bioruby+=	lib/ruby/site_ruby/1.6/bio/db/embl/trembl.rb
BUILDLINK_FILES.bioruby+=	lib/ruby/site_ruby/1.6/bio/db/fasta.rb
BUILDLINK_FILES.bioruby+=	lib/ruby/site_ruby/1.6/bio/db/genbank.rb
BUILDLINK_FILES.bioruby+=	lib/ruby/site_ruby/1.6/bio/db/genbank/ddbj.rb
BUILDLINK_FILES.bioruby+=	lib/ruby/site_ruby/1.6/bio/db/genbank/genbank.rb
BUILDLINK_FILES.bioruby+=	lib/ruby/site_ruby/1.6/bio/db/genbank/genpept.rb
BUILDLINK_FILES.bioruby+=	lib/ruby/site_ruby/1.6/bio/db/genbank/refseq.rb
BUILDLINK_FILES.bioruby+=	lib/ruby/site_ruby/1.6/bio/db/kegg/brite.rb
BUILDLINK_FILES.bioruby+=	lib/ruby/site_ruby/1.6/bio/db/kegg/cell.rb
BUILDLINK_FILES.bioruby+=	lib/ruby/site_ruby/1.6/bio/db/kegg/compound.rb
BUILDLINK_FILES.bioruby+=	lib/ruby/site_ruby/1.6/bio/db/kegg/enzyme.rb
BUILDLINK_FILES.bioruby+=	lib/ruby/site_ruby/1.6/bio/db/kegg/genes.rb
BUILDLINK_FILES.bioruby+=	lib/ruby/site_ruby/1.6/bio/db/kegg/genome.rb
BUILDLINK_FILES.bioruby+=	lib/ruby/site_ruby/1.6/bio/db/kegg/keggtab.rb
BUILDLINK_FILES.bioruby+=	lib/ruby/site_ruby/1.6/bio/db/kegg/microarray.rb
BUILDLINK_FILES.bioruby+=	lib/ruby/site_ruby/1.6/bio/db/litdb.rb
BUILDLINK_FILES.bioruby+=	lib/ruby/site_ruby/1.6/bio/db/medline.rb
BUILDLINK_FILES.bioruby+=	lib/ruby/site_ruby/1.6/bio/db/prosite.rb
BUILDLINK_FILES.bioruby+=	lib/ruby/site_ruby/1.6/bio/db/transfac.rb
BUILDLINK_FILES.bioruby+=	lib/ruby/site_ruby/1.6/bio/extend.rb
BUILDLINK_FILES.bioruby+=	lib/ruby/site_ruby/1.6/bio/feature.rb
BUILDLINK_FILES.bioruby+=	lib/ruby/site_ruby/1.6/bio/io/brdb.rb
BUILDLINK_FILES.bioruby+=	lib/ruby/site_ruby/1.6/bio/io/dbget.rb
BUILDLINK_FILES.bioruby+=	lib/ruby/site_ruby/1.6/bio/io/fetch.rb
BUILDLINK_FILES.bioruby+=	lib/ruby/site_ruby/1.6/bio/io/flatfile.rb
BUILDLINK_FILES.bioruby+=	lib/ruby/site_ruby/1.6/bio/io/flatfile/bdb.rb
BUILDLINK_FILES.bioruby+=	lib/ruby/site_ruby/1.6/bio/io/flatfile/index.rb
BUILDLINK_FILES.bioruby+=	lib/ruby/site_ruby/1.6/bio/io/flatfile/indexer.rb
BUILDLINK_FILES.bioruby+=	lib/ruby/site_ruby/1.6/bio/io/pubmed.rb
BUILDLINK_FILES.bioruby+=	lib/ruby/site_ruby/1.6/bio/io/registry.rb
BUILDLINK_FILES.bioruby+=	lib/ruby/site_ruby/1.6/bio/io/sql.rb
BUILDLINK_FILES.bioruby+=	lib/ruby/site_ruby/1.6/bio/location.rb
BUILDLINK_FILES.bioruby+=	lib/ruby/site_ruby/1.6/bio/pathway.rb
BUILDLINK_FILES.bioruby+=	lib/ruby/site_ruby/1.6/bio/reference.rb
BUILDLINK_FILES.bioruby+=	lib/ruby/site_ruby/1.6/bio/sequence.rb

.include "../../lang/ruby-base/buildlink2.mk"

BUILDLINK_TARGETS+=	bioruby-buildlink

bioruby-buildlink: _BUILDLINK_USE

.endif	# BIORUBY_BUILDLINK2_MK
